#include <cassert>
#include <iostream>
#include <string>

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

class Student {
public:
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
    Student(const std::string& name, const Score& score) :
        mName(name),
        mScore(score)
    {}

public:
    inline const std::string& GetName() const
    {
        return mName;
    }

    inline const Score& GetScore() const
    {
        return mScore;
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
    Student::Score score(92, 66, 75);
    Student student("Tanaka Miki", score);

    std::cout << "Name: " << student.GetName() << "\n"
              << "  Average: " << student.GetScore().GetAverage() << std::endl;
}