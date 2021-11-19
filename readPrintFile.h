#ifndef SOLUTION_READPRINTFILE_H
#define SOLUTION_READPRINTFILE_H

void readFile(const string &inputPath, vector<int> &data) {
    ifstream MyReadFile(inputPath);
    int num;
    while (MyReadFile >> num)
        data.push_back(num);
    MyReadFile.close();
}

void printFile(const string &outputPath, const vector<int> &data) {
    ofstream MyFile(outputPath);
    for (int x: data)
        MyFile << x << endl;
    MyFile.close();
}
void printTime(const string &filePath, const long long &runningTime)
{
    ofstream MyFile(filePath,std::ios_base::app);
    MyFile << runningTime << endl;
    MyFile.close();
}
#endif //SOLUTION_READPRINTFILE_H
