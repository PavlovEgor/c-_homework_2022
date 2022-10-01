#include <iostream>
#include <string>
#include<vector>


int main()
{   int i;
    std::vector <std::string> result;
    std::string data, s;
    std::cout<<"Give string:\n";
    getline(std::cin, data);
    for (i = 0; i < data.size(); i++){
        s = "";
        if ((data[i] >= 'A') && (data[i] <= 'z') || (data[i] == '-')) {
            s = "";
            while ((data[i] >= 'A') && (data[i] <= 'z') || (data[i] == '-')){
                s += data[i];
                i++;
            }
            result.push_back(s);
        }
        else {
            std::cout<<s<<'\n';
            if (data[i] != ' '){
                s += data[i - 1];
                std::cout<<s<<'\n';
                result.push_back(s);
            }
            else {
                continue;
            }
        }
    }
    for (i=0;i<result.size();i++){
        std::cout<<result[i]<<' ';
    }
    return 0;
}
