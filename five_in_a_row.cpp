#include <iostream>
#include <vector>
#include <cstring>

class Check_Result
{
public:
    Check_Result(std::vector<std::vector<char> > &v): m_v(v),
                                  m_white(false),
                                  m_black(false)
    {}

    void check_horizontal(const std::vector<std::vector<char> > &v);
    void check_vectical();
    void check_diagonal();
    void print_result();
    bool get_black() {return m_black;}
    bool get_white() {return m_white;} 
    const std::vector<std::vector<char> > &get_v() const {return m_v;}
    enum {BOARD_LENGTH = 15};
    enum {WIN_STEPS = 5};

private:
    std::vector<std::vector<char> > &m_v;
    bool m_black;
    bool m_white;

    void set_black() {m_black = true;}
    void set_white() {m_white = true;}
};

void Check_Result::check_horizontal(const std::vector<std::vector<char> > &v)
{
    for (int i = 0; i != v.size(); i++)
    {
        std::string line(v[i].begin(), v[i].end()); // each line
        int found_5B = line.find("BBBBB");
        int found_5W = line.find("WWWWW");

        if (found_5B != -1)
        {
            set_black();
        }
        if (found_5W != -1)
        {
            set_white();
        }

    }
}

void Check_Result::print_result()
{
    if (m_black && m_white) // both
    {
        std::cout << "Both\n";
    }

    else if (m_black)
    {
        std::cout << "Black\n";
    }

    else if (m_white)
    {
        std::cout << "White\n";
    }

    else
    {
        std::cout << "None\n";
    }
}

void Check_Result::check_vectical()
{
    std::vector<std::vector<char> > vh;
    for (int j = 0; j != BOARD_LENGTH; j++)
    {
        std::vector<char> tmp_v;
        for (int i = 0; i != BOARD_LENGTH; i++)
        {
            tmp_v.push_back(m_v[i][j]);
        }
        vh.push_back(tmp_v); 
        
    }
    check_horizontal(vh);
}
void Check_Result::check_diagonal()
{
    // m_v[i][j]
    // i = BOARD_LENGTH-1 -y;
    // j = x;
    std::vector<std::vector<char> > vd;
    // y = x + b;
    for (int b = -(BOARD_LENGTH-WIN_STEPS); b != (BOARD_LENGTH-WIN_STEPS+1); b++)
    {
        std::vector<char> tmp_v;
        for (int x = (b>=0)?0:-b; x != ((b>=0)?(BOARD_LENGTH-b):BOARD_LENGTH); x++)
        {
            tmp_v.push_back(m_v[(BOARD_LENGTH-1)-(x+b)][x]);
        }
        vd.push_back(tmp_v);
    }

    // y = -x + b;
    for (int b = WIN_STEPS-1; b != ( 2*(BOARD_LENGTH-1) - (WIN_STEPS-1) ); b++)
    {
        std::vector<char> tmp_v;
        if (b>=4 && b<= 14)
        {
            for (int x = 0; x != b+1; x++)
            {
                tmp_v.push_back(m_v[(BOARD_LENGTH-1)-(-x+b)][x]);
            }
        }
        else if (b>= BOARD_LENGTH && b<= ( 2*(BOARD_LENGTH-1) - (WIN_STEPS-1) ))
        {
            for (int x = b-(BOARD_LENGTH-1); x != BOARD_LENGTH; x++)
            {
                tmp_v.push_back(m_v[(BOARD_LENGTH-1)-(-x+b)][x]);
            }
        }
        vd.push_back(tmp_v);
    }

    check_horizontal(vd);
}

int main(void)
{
    int case_num = 0;
    std::cin >> case_num;
    std::cin.clear();   // clear the cin stream
    std::cin.ignore(Check_Result::BOARD_LENGTH, '\n');
    std::vector< std::vector< std::vector<char> > > v_result;
    for (int i = 0; i != case_num; i++)
    {
        // input
        std::vector<std::vector<char> >v_input;
        for (int j = 0; j != Check_Result::BOARD_LENGTH; j++)
        {
            // input
            char line[Check_Result::BOARD_LENGTH + 1];
            std::cin.getline(line, Check_Result::BOARD_LENGTH + 1);
            std::vector<char> tmp_v(line, line+std::strlen(line));
            v_input.push_back(tmp_v);
        }
        v_result.push_back(v_input);
    }

    for (int i = 0; i != case_num; i++)
    {
        Check_Result result(v_result[i]);
        result.check_horizontal(result.get_v()); // horizontal check
        result.check_vectical();    // vertical check
        result.check_diagonal();    // check diagonal

        result.print_result();

    }

    return 0;
}
