#include <bits/stdc++.h>

using namespace std;


struct student 
{
    int std_id;
    vector<int>asked_question;
};

struct ques
{
    int qs_id;
    int ans_id;
    int student_id;
    string question;
    bool solved = false;
};

struct ans
{
    int qs_id;
    int ans_id;
    string solution;
};

int q_id_seed=1000;
int a_id_seed=1000;

int main()
{
    student inan;
    vector<ques> unanswered;
    map<int, ques> parmanent_ques;
    map<int, ans> parmanent_ans;

    //Student asking question;
    string asked_question="what is your name";
    int asked_qid = ++q_id_seed;
    inan.asked_question.push_back(asked_qid);
    
    //Storing question permanent and unanswered
    ques temp;
    temp.qs_id=q_id_seed;
    temp.student_id = inan.std_id;
    temp.question = asked_question;
    unanswered.push_back(temp);
    parmanent_ques[q_id_seed] = temp;

    //Teacher solving all question and storing it
    while(!unanswered.empty())
    {
        ques temp2 = unanswered.front();
        int current_qid = temp2.qs_id;
        string current_q = temp2.question;

        //Solving question
        string current_q_solution = "I solved it";
        int solution_id = ++a_id_seed;

        //updating question state
        parmanent_ques[current_qid].solved = true;
        parmanent_ques[current_qid].ans_id = solution_id;

        //storing answer
        ans temp3;
        temp3.qs_id = current_qid;
        temp3.ans_id = solution_id;
        temp3.solution = current_q_solution;
        parmanent_ans[solution_id] = temp3;

        //removing from unanswered
        unanswered.erase(unanswered.begin());
    }

    //Specific Student notification
    for (int i = 0; i < inan.asked_question.size(); i++)
    {
        int now_q_id = inan.asked_question[i];
        if (parmanent_ques[now_q_id].solved)
        {
            cout << parmanent_ans[parmanent_ques[now_q_id].ans_id].solution << endl;
            
            //you can erase student's unanswered question here, to reduce it's size more. 
        }
        else 
        {
            //No notification
        }
    }

    return 0;
}
