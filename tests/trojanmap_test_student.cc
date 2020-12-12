#include "src/lib/trojanmap.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

TEST(TrojanMapTest, Autocomplete) {
  TrojanMap t;
  t.CreateGraphFromCSVFile();
  std::vector<std::string> exp = {"Ralphs", "Rance39s Chicago Pizza", "Ramen KenJo"};
  std::vector<std::string> res = t.Autocomplete("ra");
  for(int i=0; i<int(res.size()); i++){
    EXPECT_EQ(res[i], exp[i]);
  }
  res = t.Autocomplete("Ra");
  for(int i=0; i<int(res.size()); i++){
    EXPECT_EQ(res[i], exp[i]);
  }
}

TEST(TrojanMapTest, GetPosition) {
  TrojanMap t;
  t.CreateGraphFromCSVFile();
  std::pair<double, double> res = t.GetPosition("Ramen KenJo");
  std::pair<double, double> exp(34.0249482, -118.2851489);
  EXPECT_EQ(res, exp);
}

TEST(TrojanMapTest, CalculateShortestPath) {
  TrojanMap t;
  t.CreateGraphFromCSVFile();
  std::vector<std::string> res = t.CalculateShortestPath("7Eleven", "Lawn");
  std::vector<std::string> exp = {"5695236165", "3438433461", "4835551077", "4835551072", "5680945537", "123241961", "6813565326", "4012842277",
                                  "4835551064", "5556117115", "5556117120", "20400292", "6813513564", "6813513563", "122659187", "7863689395", 
                                  "4835551084", "2613117900", "7863656075", "7863689388", "6807580191", "6787803674", "6787803666", "6787803661",
                                  "6787803658", "6787803653", "6787803649", "6816822864", "122659191", "2613117891", "6813379507", "6985903602",
                                  "6813416161", "122814440", "6813416162", "2613117899", "7601578291", "6813379508", "122719213", "6813379510",
                                  "441895675", "4399698024", "4399698025", "214470797", "4399698026", "4399698027", "6813405233", "122719216",
                                  "6813405231", "2613117893", "122719255", "7591500905", "7591500900", "7591500901", "7591500902", "7591500903",
                                  "7591500907", "7591500904", "7591500906", "1849116066", "1849116072", "1849116069", "6229624525", "1849116060", 
                                  "6047218633", "1849116064", "1849116062", "6047234446"};
  for(int i=0; i<int(res.size()); i++){
    EXPECT_EQ(res[i], exp[i]);
  }
}

TEST(TrojanMapTest, TSP) {
  TrojanMap t;
  t.CreateGraphFromCSVFile();
  std::vector<std::string> ids = {"6819220738", "348122895", "6819220738", "6813405268", "5172201326", "6805603628", "6820982894"};
  std::pair<double, std::vector<std::vector<std::string>>> res = t.TravellingTrojan(ids);
  std::vector<std::string> ideal = {"6819220738", "348122895", "6813405268", "5172201326", "6805603628", "6820982894","6819220738", "6819220738"};
  double explen = t.CalculatePathLength(ideal);
  EXPECT_EQ(res.first, explen);

}