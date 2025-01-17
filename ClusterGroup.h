#include <algorithm>
#include <array>
#include <string>
#include <iostream> // std::cout

#include "htypes.h"

#include "swap_sorted_patterns.h"

namespace sh {


	/**
	 * Helper class to efficiently compute partially ordered pattern sets.
	 * The inputs of the network are grouped together in clusters that have been connected by CEs
	 * Initial clusters contain just one input (no CEs added yet).
	 * Each cluster has a set of output patterns that it leaves behind. The global set of output patterns
	 * is at each time defined by the bitwise "ORed" combinations of the outputs that all clusters produce together.
	 * While adding CEs to the network, clusters are combined into larger clusters with a shrinking total number of
	 * output patterns. If the CE is added that combines the last two clusters, only one cluster will remain.
	 * If after that sufficient new CEs are added, only ninputs+1 patterns will remain, meaning that the network is fully sorted.
	 */

	template <int N>
	class ClusterGroup {
	private:
		//int N; ///< Total number of inputs (and outputs) of the network
		std::array<SinglePatternList_t, N> pattern_lists; ///< Sorted list of output patterns from each cluster of lines
		std::array<SortWord_t, N> masks; ///< Masks for each cluster marking the applicable lines for each cluster
		std::array<int, N> clusterAlloc; ///< Allocations of lines to clusters

	public:

		// Initialize an empty cluster group
		ClusterGroup() {
			this->clear();
		}

		// Copy constructor
		ClusterGroup(const ClusterGroup& cg)
		{
			for (int k = 0; k < N; k++)
			{
				this->pattern_lists[k] = cg.pattern_lists[k];
				this->masks[k] = cg.masks[k];
				this->clusterAlloc[k] = cg.clusterAlloc[k];
			}
		}

		// Assignment of cluster groups to each other
		ClusterGroup& operator=(const ClusterGroup& cg)
		{
			for (int k = 0; k < N; k++)
			{
				this->pattern_lists[k] = cg.pattern_lists[k];
				this->masks[k] = cg.masks[k];
				this->clusterAlloc[k] = cg.clusterAlloc[k];
			}
			return *this;
		}

		/**
		* Set initial state:
		* each input corresponds one to one with its own cluster. The cluster has two possible output patterns:
		* the all 0 pattern, and a single 1 bit at the bit position of the corresponding input.
		*/
		void clear()
		{
			for (int k = 0; k < N; k++)
			{
				this->clusterAlloc[k] = k;
				this->masks[k] = static_cast<SortWord_t>(1) << k;
				this->pattern_lists[k].clear();
				this->pattern_lists[k].push_back(0);
				this->pattern_lists[k].push_back(static_cast<SortWord_t>(1) << k);
			}
		}

		/**
		* Reduces the number of patterns represented by appending a single CE to the network.
		* If the CE's lines belong to different clusters, the clusters are merged first.
		* @param p CE represented by its input/output lines
		*/
		void preSort(const Pair_t& p)
		{
			const int ci_idx = clusterAlloc[p.lo];
			const int cj_idx = clusterAlloc[p.hi];

			if (ci_idx != cj_idx)
			{
				combine(ci_idx, cj_idx);
			}
			swap_sorted_patterns(pattern_lists[ci_idx], p);
		}

		/**
		* Compute the list of output patterns that can leave the network composed of all
		* clusters remaining. This is done by "ORing" together output combinations of all remaining clusters.
		* @param patterns [OUT] pattern list created (not lexigraphically sorted)
		*/
		void computeOutputs(INOUT SinglePatternList_t& patterns) const
		{
			std::array<SinglePatternList_t const*, NMAX> pLists;
			int n_to_combine = 0;

			for (int k = 0; k < N; k++)
			{
				if (this->masks[k] != 0) {
					const auto& x = this->pattern_lists[k];
					pLists[n_to_combine] = &x;
					n_to_combine++;
				}
			}
			//std::cout << "computeOutputs: n_to_combine = " << n_to_combine << std::endl;

			assert(n_to_combine > 0);

			int level = 0;
			
			std::array<int, NMAX> indices;
			std::array<SortWord_t, NMAX> outmasks;
			indices.fill(0);
			outmasks.fill(0);
			patterns.clear();

			while (level >= 0)
			{
				const int x = static_cast<int>(pLists[level]->size());
				if (indices[level] < x)
				{
					const int idx = indices[level];
					const SinglePatternList_t* const y = pLists[level];
					const SortWord_t z = (*y)[idx];
						
					if (level == 0) {
						outmasks[level] = z;
						//std::cout << "computeOutputs: A1: outmasks[" << level << "]=z" << std::endl;
					}
					else {
						outmasks[level] = outmasks[level - 1] | z;
						//std::cout << "computeOutputs: A2: outmasks[" << level << "]=z" << std::endl;
					}

					if (level < (n_to_combine - 1))
					{
						indices[level + 1] = 0;
						indices[level]++;
						level++;
						//std::cout << "computeOutputs: B1: level=" << level << std::endl;
					}
					else
					{
						patterns.push_back(outmasks[level]);
						indices[level]++;
						//std::cout << "computeOutputs: B2: indices[" << level << "]=" << indices[level] << std::endl;
					}
				}
				else
				{
					level--;
					//std::cout << "computeOutputs: C: level=" << level << std::endl;
				}
			}
		}

		/**
		* Compute number of output patterns that would be produced by call to computeOutputs
		*/
		SortWord_t outputSize() const
		{
			SortWord_t prod = 1;

			for (int k = 0; k < N; k++)
			{
				if (masks[k] != 0) {
					prod *= static_cast<SortWord_t>(pattern_lists[k].size());
				}
			}

#if 1
			if (prod == 0) { // Special case for N=NMAX, dirty hack avoiding wrap-around to 0 of empty network: set size to one less.
				prod -= 1;
			}
#endif

			return prod;
		}

		bool isSameCluster(const Pair_t& p) const
		{
			const auto ci_idx = clusterAlloc[p.lo];
			const auto cj_idx = clusterAlloc[p.hi];
			return ci_idx == cj_idx;
		}

	private:

		/**
		* Combines two clusters to form a larger cluster.
		* The output pattern list is produced by bitwise "oring" of both original pattern lists
		* @param ci_idx First cluster index (new result cluster)
		* @param cj_idx Second cluster index (will no longer be used)
		*/
		void combine(int ci_idx, int cj_idx)
		{
			SinglePatternList_t& p1 = pattern_lists[ci_idx];
			SinglePatternList_t& p2 = pattern_lists[cj_idx];

			for (int k = 0; k < N; k++) {
				if (clusterAlloc[k] == cj_idx) {
					clusterAlloc[k] = ci_idx; // ci will take over
				}
			}
			masks[ci_idx] |= masks[cj_idx];
			SinglePatternList_t cp;
			/*
			* Combined cluster's output patterns are here simply generated by producing all
			* patterns, first disregarding their final order and sorting them afterwards.
			* At first, I had an algorithm in place that broke the masks into chunks allowing
			* in order generation that had lower theoretical complexity. For practical sizes however
			* a quicksort proved a faster and simpler alternative. (and probably has less bugs :-) )
			*/
			for (int i = 0; i < static_cast<int>(p1.size()); i++) {
				for (int j = 0; j < static_cast<int>(p2.size()); j++) {
					cp.push_back(p1[i] | p2[j]);
				}
			}
			std::sort(cp.begin(), cp.end()); // Keep the new output set sorted
			p1 = cp;
			masks[cj_idx] = 0;
			p2.clear();
		}
	};
}
