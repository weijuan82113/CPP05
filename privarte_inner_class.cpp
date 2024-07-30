#include <cassert>
#include <iostream>
#include <string>

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

class Student {
private:
    class Score {
    public:
        Score(int japanese, int math, int english);

    public:
        // 平均点を返す
        int GetAverage() const;

    private:
        enum Subject {
            SUBJECT_JAPANESE,
            SUBJECT_MATH,
            SUBJECT_ENGLISH,

            SUBJECT_NUM,  // 総数を表すダミー
        };

    private:
        int  mScores[SUBJECT_NUM];
    };

public:
    Student(const std::string& name, int japanese, int math, int english) :
        mName(name),
        mScore(japanese, math, english)
    {}

public:
    inline const std::string& GetName() const
    {
        return mName;
    }

    // 平均点を返す
    inline int GetAverage() const
    {
        return mScore.GetAverage();
    }

private:
    const std::string  mName;
    const Score        mScore;
};

Student::Score::Score(int japanese, int math, int english)
{
    mScores[SUBJECT_JAPANESE] = japanese;
    mScores[SUBJECT_MATH]     = math;
    mScores[SUBJECT_ENGLISH]  = english;
}

int Student::Score::GetAverage() const
{
    int sum = 0;
    for (int i = 0; i < SIZE_OF_ARRAY(mScores); ++i) {
        sum += mScores[i];
    }
    return sum / SIZE_OF_ARRAY(mScores);
}


int main()
{
    Student student("Tanaka Miki", 92, 66, 75);

    std::cout << "Name: " << student.GetName() << "\n"
              << "  Average: " << student.GetAverage() << std::endl;
}