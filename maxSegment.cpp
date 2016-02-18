int maxSegment(vector<int>& seg1, vector<int>& seg2){
  vector<pair<int,char>> sum;
  for(int i = 0 ; i < seg1.size(); i++){
    // sum.push_back(make_pair())
    sum.push_back(make_pair(seg1[i],'S'));
  }
  for(int j = 0; j < seg2.size(); j++){
    sum.push_back(make_pair(seg2[j], 'X'));   // char is single ' ' ,'X' will help make seg2 appear after seg1
  }
  sort(sum.begin(), sum.end());
  int maxNum = 0;
  int start = 0;
  for(int i = 0; i < sum.size(); i++){
    if(sum[i].second == 'S') start++;
    if(sum[i].second == 'X') start--;
    maxNum = max(maxNum, start); 
  }
  return maxNum;
}
  
int main() {
  vector<int> starts {3, 1, 2, 5, 11};
  vector<int> ends {5, 9, 10, 7, 13};
  
  cout << maxSegment(starts, ends) << endl;
  return 0;
}
