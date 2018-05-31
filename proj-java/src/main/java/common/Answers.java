package common;


/**
 * Estrutura de dados de Posts tipo 2
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

public class Answers extends Posts {
    private long parent_id; // a que pergunta pertence
    private int score;
    private int comment_count; //número de comentários recebidos pela resposta (query 10)

    /**
     * Construtor por omissão de Answers.
     */
    public Answers() {
        super();
        parent_id = 0;
        score = 0;
        comment_count = 0;
    }

    /**
     * Construtor parametrizado de Users.
     *
     * @param user_id Identificador do user
     * @param post_id Identificador do post
     * @param parent_id Identificador da pergunta a que se refere
     * @param score Score da resposta
     * @param comment_count Número de comentários
     */
    public Answers(long user_id, long post_id, long parent_id, int score, int comment_count) {
        super(user_id, post_id);
        this.parent_id = parent_id;
        this.score = score;
        this.comment_count = comment_count;
    }

    /**
     * Construtor de Cópia.
     *
     * @param umCI Contribuinte Individual a ser replicado
     */
    public Answers(Answers a) {
        super(a);
        this.parent_id = a.getParentId();
        this.score = a.getScore();
        this.comment_count = a.getCommentCount();
    }

    /**
     * Função que devolve o id da pergunta a que a resposta pertence.
     *
     * @returns long - Identificador da pergunta a que a resposta pertence.
     */
    public long getParentId() {
        return parent_id;
    }

    /**
     * Função que estabelece o id da pergunta a que a resposta pertence.
     *
     * @param id Identificador da pergunta a que a resposta pertence.
     */
    public void setParentId(long id) {
        parent_id = id;
    }

    /**
     * Função que devolve o score da resposta
     *
     * @returns int - score
     */
    public int getScore() {
        return score;
    }

    /**
     * Função que estabelece o score da resposta
     *
     * @param score Score da resposta
     */
    public void setScore(int score) {
        this.score = score;
    }

    /**
     * Função que devolve o número de comentários da resposta.
     *
     * @returns int - número de comentários
     */
    public int getCommentCount() {
        return comment_count;
    }

    /**
     * Função que estabelece o número de comentários da resposta.
     *
     * @param comment_count o número de comentários da resposta.
     */
    public void setCommentCount(int comment_count) {
        this.comment_count = comment_count;
    }

    public Answers clone() {
         return new Answers(this);
    }
    
    /**
     * Método que determina se duas respostas são iguais.
     *
     * @param object Objecto a ser usado como termo de comparação.
     *
     * @return Boolean indicando se os dois objetos são iguais
     */
    public boolean equals(Object object) {
        if(this == object)
            return true;

        if(object == null || (this.getClass() != object.getClass()))
            return false;

        Answers resposta = (Answers) object;
        return  (super.equals(resposta) && parent_id == resposta.getParentId() 
                 && score == resposta.getScore() && comment_count == resposta.getCommentCount());

    }
    
     /**
     * Método que devolve a representação em String de Answers.
     *
     * @return String que representa uma resposta.
     */
    public String toString() {

        return "Answers{" +
                super.toString() +
                ", ParentId = " + parent_id +
                ", Score = " + score +
                ", CommentCount = " + comment_count +
                '}';
    }
}
