class Parser
{
private:
    char lookahead;
    void Expr();
    void Term();
    void R();
    void Match(char t);
public:
    Parser();
    void Start();
};
