// Matriz armazenada em ponteiro simples
typedef struct {
  int lin, col; // linhas e colunas
  float *data;  // dados
} mtzseq;

mtzseq new_mtzseq(int lin, int col, float init);
void free_mtzseq(mtzseq *m);
void mset(mtzseq m, int i, int j, float v);
float mget(mtzseq m, int i, int j);
void mtzseq_read(mtzseq m);
void mtzseq_print(mtzseq m);
mtzseq soma_mtzseq(mtzseq A, mtzseq B);
mtzseq ppscalar_mtzseq(mtzseq m, float num);
mtzseq transposta_mtzseq(mtzseq m);
mtzseq mul_mtzseq(mtzseq A, mtzseq B);
