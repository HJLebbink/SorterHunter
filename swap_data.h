#pragma once
#include <vector>
namespace sh {
	const std::vector<std::vector<std::pair<int, int>>> sn_8 = std::vector<std::vector<std::pair<int, int>>>{
		{{0,2},{1,3},{4,6},{5,7}},
		{{0,4},{1,5},{2,6},{3,7}},
		{{0,1},{2,3},{4,5},{6,7}},
		{{2,4},{3,5}},
		{{1,4},{3,6}},
		{{1,2},{3,4},{5,6}},
	};

	const std::vector<std::vector<std::pair<int, int>>> sn_16 = std::vector<std::vector<std::pair<int, int>>>{
		{{0,5},{1,4},{2,12},{3,13},{6,7},{8,9},{10,15},{11,14}},
		{{0,2},{1,10},{3,6},{4,7},{5,14},{8,11},{9,12},{13,15}},
		{{0,8},{1,3},{2,11},{4,13},{5,9},{6,10},{7,15},{12,14}},
		{{0,1},{2,4},{3,8},{5,6},{7,12},{9,10},{11,13},{14,15}},
		{{1,3},{2,5},{4,8},{6,9},{7,11},{10,13},{12,14}},
		{{1,2},{3,5},{4,11},{6,8},{7,9},{10,12},{13,14}},
		{{2,3},{4,5},{6,7},{8,9},{10,11},{12,13}},
		{{4,6},{5,7},{8,10},{9,11}},
		{{3,4},{5,6},{7,8},{9,10},{11,12}},
	};

	const std::vector<std::vector<std::pair<int, int>>> sn_32 = std::vector<std::vector<std::pair<int, int>>>{
		{{0,1},{2,3},{4,5},{6,7},{8,9},{10,11},{12,13},{14,15},{16,17},{18,19},{20,21},{22,23},{24,25},{26,27},{28,29},{30,31}},
		{{0,2},{1,3},{4,6},{5,7},{8,10},{9,11},{12,14},{13,15},{16,18},{17,19},{20,22},{21,23},{24,26},{25,27},{28,30},{29,31}},
		{{0,4},{1,5},{2,6},{3,7},{8,12},{9,13},{10,14},{11,15},{16,20},{17,21},{18,22},{19,23},{24,28},{25,29},{26,30},{27,31}},
		{{0,8},{1,9},{2,10},{3,11},{4,12},{5,13},{6,14},{7,15},{16,24},{17,25},{18,26},{19,27},{20,28},{21,29},{22,30},{23,31}},
		{{0,16},{1,8},{2,4},{3,12},{5,10},{6,9},{7,14},{11,13},{15,31},{17,24},{18,20},{19,28},{21,26},{22,25},{23,30},{27,29}},
		{{1,2},{3,5},{4,8},{6,22},{7,11},{9,25},{10,12},{13,14},{17,18},{19,21},{20,24},{23,27},{26,28},{29,30}},
		{{1,17},{2,18},{3,19},{4,20},{5,10},{7,23},{8,24},{11,27},{12,28},{13,29},{14,30},{21,26}},
		{{3,17},{4,16},{5,21},{6,18},{7,9},{8,20},{10,26},{11,23},{13,25},{14,28},{15,27},{22,24}},
		{{1,4},{3,8},{5,16},{7,17},{9,21},{10,22},{11,19},{12,20},{14,24},{15,26},{23,28},{27,30}},
		{{2,5},{7,8},{9,18},{11,17},{12,16},{13,22},{14,20},{15,19},{23,24},{26,29}},
		{{2,4},{6,12},{9,16},{10,11},{13,17},{14,18},{15,22},{19,25},{20,21},{27,29}},
		{{5,6},{8,12},{9,10},{11,13},{14,16},{15,17},{18,20},{19,23},{21,22},{25,26}},
		{{3,5},{6,7},{8,9},{10,12},{11,14},{13,16},{15,18},{17,20},{19,21},{22,23},{24,25},{26,28}},
		{{3,4},{5,6},{7,8},{9,10},{11,12},{13,14},{15,16},{17,18},{19,20},{21,22},{23,24},{25,26},{27,28}},
	};

	const std::vector<std::vector<std::pair<int, int>>> sn_64 = std::vector<std::vector<std::pair<int, int>>>{
		{{0,2},{1,3},{4,6},{5,7},{8,10},{9,11},{12,14},{13,15},{16,18},{17,19},{20,22},{21,23},{24,26},{25,27},{28,30},{29,31},{32,34},{33,35},{36,38},{37,39},{40,42},{41,43},{44,46},{45,47},{48,50},{49,51},{52,54},{53,55},{56,58},{57,59},{60,62},{61,63}},
		{{0,1},{2,3},{4,5},{6,7},{8,9},{10,11},{12,13},{14,15},{16,17},{18,19},{20,21},{22,23},{24,25},{26,27},{28,29},{30,31},{32,33},{34,35},{36,37},{38,39},{40,41},{42,43},{44,45},{46,47},{48,49},{50,51},{52,53},{54,55},{56,57},{58,59},{60,61},{62,63}},
		{{0,20},{1,2},{3,23},{4,16},{5,6},{7,19},{8,48},{9,10},{11,51},{12,52},{13,14},{15,55},{17,18},{21,22},{24,28},{25,26},{27,31},{29,30},{32,36},{33,34},{35,39},{37,38},{40,60},{41,42},{43,63},{44,56},{45,46},{47,59},{49,50},{53,54},{57,58},{61,62}},
		{{0,8},{1,21},{2,22},{3,11},{4,40},{5,17},{6,18},{7,43},{9,49},{10,50},{12,24},{13,53},{14,54},{15,27},{16,28},{19,31},{20,56},{23,59},{25,29},{26,30},{32,44},{33,37},{34,38},{35,47},{36,48},{39,51},{41,61},{42,62},{45,57},{46,58},{52,60},{55,63}},
		{{0,32},{1,9},{2,10},{3,35},{4,12},{5,41},{6,42},{7,15},{8,44},{11,47},{13,25},{14,26},{16,52},{17,29},{18,30},{19,55},{20,36},{21,57},{22,58},{23,39},{24,40},{27,43},{28,60},{31,63},{33,45},{34,46},{37,49},{38,50},{48,56},{51,59},{53,61},{54,62}},
		{{0,4},{1,33},{2,34},{3,7},{5,13},{6,14},{8,16},{9,45},{10,46},{11,19},{12,32},{15,35},{17,53},{18,54},{20,24},{21,37},{22,38},{23,27},{25,41},{26,42},{28,48},{29,61},{30,62},{31,51},{36,40},{39,43},{44,52},{47,55},{49,57},{50,58},{56,60},{59,63}},
		{{1,5},{2,6},{4,12},{7,15},{8,20},{9,17},{10,18},{11,23},{13,33},{14,34},{16,32},{19,35},{21,25},{22,26},{24,36},{27,39},{28,44},{29,49},{30,50},{31,47},{37,41},{38,42},{40,52},{43,55},{45,53},{46,54},{48,56},{51,59},{57,61},{58,62}},
		{{4,8},{5,13},{6,14},{7,11},{9,21},{10,22},{12,20},{15,23},{16,44},{17,33},{18,34},{19,47},{24,32},{25,37},{26,38},{27,35},{28,36},{29,45},{30,46},{31,39},{40,48},{41,53},{42,54},{43,51},{49,57},{50,58},{52,56},{55,59}},
		{{5,9},{6,10},{8,12},{11,15},{13,21},{14,22},{16,20},{17,45},{18,46},{19,23},{24,28},{25,33},{26,34},{27,31},{29,37},{30,38},{32,36},{35,39},{40,44},{41,49},{42,50},{43,47},{48,52},{51,55},{53,57},{54,58}},
		{{9,13},{10,14},{16,24},{17,21},{18,22},{19,27},{20,28},{23,31},{25,29},{26,30},{32,40},{33,37},{34,38},{35,43},{36,44},{39,47},{41,45},{42,46},{49,53},{50,54}},
		{{12,16},{15,19},{17,25},{18,26},{20,24},{21,29},{22,30},{23,27},{28,32},{31,35},{33,41},{34,42},{36,40},{37,45},{38,46},{39,43},{44,48},{47,51}},
		{{1,16},{2,32},{5,20},{6,36},{9,24},{10,40},{13,17},{14,18},{21,25},{22,26},{23,53},{27,57},{29,33},{30,34},{31,61},{37,41},{38,42},{39,54},{43,58},{45,49},{46,50},{47,62}},
		{{1,4},{2,8},{3,33},{6,12},{7,37},{10,24},{11,41},{13,28},{14,44},{15,45},{18,48},{19,49},{21,36},{22,52},{26,56},{27,42},{30,60},{35,50},{39,53},{51,57},{55,61},{59,62}},
		{{2,4},{3,17},{5,6},{7,22},{8,16},{11,25},{12,20},{14,28},{15,29},{18,32},{19,33},{23,37},{26,40},{30,44},{31,45},{34,48},{35,49},{38,52},{41,56},{43,51},{46,60},{47,55},{57,58},{59,61}},
		{{3,18},{7,21},{11,32},{15,30},{17,26},{19,25},{22,36},{23,29},{27,41},{31,52},{33,48},{34,40},{37,46},{38,44},{42,56},{45,60}},
		{{3,16},{7,20},{11,24},{15,21},{17,18},{19,34},{22,28},{23,38},{25,40},{26,32},{27,33},{29,44},{30,36},{31,37},{35,41},{39,52},{42,48},{43,56},{45,46},{47,60}},
		{{3,9},{7,13},{10,16},{11,17},{14,20},{15,22},{18,24},{19,26},{21,28},{23,30},{25,32},{27,34},{29,36},{31,38},{33,40},{35,42},{37,44},{39,45},{41,48},{43,49},{46,52},{47,53},{50,56},{54,60}},
		{{3,8},{7,10},{9,12},{11,16},{13,14},{15,17},{18,20},{19,22},{21,24},{23,26},{25,28},{27,29},{30,32},{31,33},{34,36},{35,38},{37,40},{39,42},{41,44},{43,45},{46,48},{47,52},{49,50},{51,54},{53,56},{55,60}},
		{{3,5},{6,8},{7,9},{10,12},{11,13},{14,16},{15,18},{17,20},{19,21},{22,24},{23,25},{26,28},{27,30},{29,32},{31,34},{33,36},{35,37},{38,40},{39,41},{42,44},{43,46},{45,48},{47,49},{50,52},{51,53},{54,56},{55,57},{58,60}},
		{{3,4},{5,6},{7,8},{9,10},{11,12},{13,14},{15,16},{17,18},{19,20},{21,22},{23,24},{25,26},{27,28},{29,30},{31,32},{33,34},{35,36},{37,38},{39,40},{41,42},{43,44},{45,46},{47,48},{49,50},{51,52},{53,54},{55,56},{57,58},{59,60}},
	};

	inline std::vector<std::vector<std::pair<int, int>>> get_sort_network(int channels) {
		switch (channels) {
		case 8: return sn_8;
		case 16: return sn_16;
		case 32: return sn_32;
		case 64: return sn_64;
		default:
			std::cout << "ERROR: " << std::endl;
			return std::vector<std::vector<std::pair<int, int>>>();
		}
	}
}