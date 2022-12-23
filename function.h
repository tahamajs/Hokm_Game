void max_zero(int max_card[]);

void shuffle_card(int* card);

int win_calculator(int hokm,int max_card[],int score[]);

int chooose(int bakhsh,int *first_card,int p[],int max_card[],int partner_tern);

int choose(int p[11], int bakhsh, int *first_card, int state,int max_card[]);

void print(int score[],int p[],int max_card[4]);

void bradcast(int arr[] ,int p1[],int p2[],int p3[],int p4[],int status,int f);

void get_input(int p1[],int *first_card , int hokm , int *char_hokm ,int max_card[],int *ans,int score[]);

int play(int score[],int p1[],int p2[],int p3[],int p4[],int arr[],int num_starter,int *first_card,int hokm,int max_card[]);