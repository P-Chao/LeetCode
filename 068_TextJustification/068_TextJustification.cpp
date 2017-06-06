#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth){
		if (words.empty() || maxWidth == 0){
			return words;
		}

		vector<string> text, line;
		vector<pair<vector<string>, int>> lines;

		const int n = words.size();
		int curWidth = 0, spaceWidth = maxWidth;
		int lnum = 0;
		for (int i = 0; i < n; ++i){
			int wlen = words[i].size();
			if (curWidth + wlen == maxWidth){
				line.push_back(words[i]);
				lines.push_back({ line, spaceWidth - wlen });
				line.clear();
				curWidth = 0;
				spaceWidth = maxWidth;
			}
			else if (curWidth + wlen > maxWidth){
				lines.push_back({ line, spaceWidth });
				line.clear();
				curWidth = 0;
				spaceWidth = maxWidth;
				--i;
			}
			else if (curWidth + wlen < maxWidth){
				line.push_back(words[i]);
				spaceWidth -= wlen;
				curWidth += (wlen + 1);
			}
		}

		if (!line.empty()){
			lines.push_back({ line, spaceWidth });
		}

		for (int i = 0; i < lines.size() - 1; ++i){
			string textline;
			line = lines[i].first;
			spaceWidth = lines[i].second;
			if (line.size() == 1){
				textline += line[0];
				while (spaceWidth){
					spaceWidth--;
					textline += " ";
				}
				text.push_back(textline);
			}
			else{
				int spaceL = spaceWidth / (line.size() - 1);
				int spaceR = spaceWidth % (line.size() - 1);
				for (int j = 0; j < line.size(); ++j){
					int space = spaceL;
					if (spaceR){
						spaceR--;
						space++;
					}
					textline += line[j];
					
					while (space && j != line.size() - 1){
						space--;
						textline += " ";
					}
					
				}
				text.push_back(textline);
			}
		}

		if (!lines.empty()){
			string textline;
			line = lines[lines.size() - 1].first;
			spaceWidth = lines[lines.size() - 1].second;
			if (line.size() == 1){
				textline += line[0];
				while (spaceWidth){
					spaceWidth--;
					textline += " ";
				}
				text.push_back(textline);
			}
			else{
				for (int i = 0; i < line.size(); ++i){
					spaceWidth--;
					textline += line[i];
					textline += " ";
					while (spaceWidth && i == line.size() - 1){
						spaceWidth--;
						textline += " ";
					}
				}
				text.push_back(textline);
			}
		}

		return text;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.fullJustify(vector<string>{"a"}, 1);
	for (auto v : vs){
		cout << v << endl;
	}
	system("pause");
	return 0;
}