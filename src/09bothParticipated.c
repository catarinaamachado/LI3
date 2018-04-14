#include "struct.h"


/*
Função que verifica se determinado utilizador respondeu a determinada questão.
*/
static int participateAnswers(Questions q, long id) {
    int size = getNAnswers(q);

    for (int i = 0; i < size; i++)
        if (id == getAnswerUserIdAtIndex(q, i))
            return 1;

    return 0;
}


/*
Dados os IDs de dois utilizadores, devolver as últimas
N perguntas (cronologia inversa) em que participaram dois utilizadores específicos.
Note que os utilizadores podem ter participado via pergunta ou respostas.
*/
LONG_list both_participated(TAD_community com, long id1, long id2, int N) {
    LONG_list ll = create_list(N);

    GList * l;

    int i = 0, id1P = 0, id2P = 0;
    long uid;

    for (l = getQuestions(com); N-i > 0 && l != NULL; l = l->next) {
        Questions q = l->data;

        uid = getQUserId(q);

        if(uid == id1)
            id1P = 1;
        else
            id1P = participateAnswers(q, id1);

        if(id1P) {
            if(uid == id2)
                id2P = 1;
            else
                id2P = participateAnswers(q, id2);

            if(id2P) {
                set_list(ll, i, getQuestionId(q));
                i++;
            }
        }

    }

    return ll;
}
