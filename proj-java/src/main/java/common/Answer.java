package common;

/**
 * Estrutura de dados de Posts tipo 2
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.time.LocalDate;

public class Answer extends Posts {
    private long parent_id; // a que pergunta pertence
    private int score;
    private int comment_count; //número de comentários recebidos pela resposta (query 10)

    /**
     * Construtor por omissão de Answer.
     */
    public Answer() {
        super();
        this.parent_id = 0;
        this.score = 0;
        this.comment_count = 0;
    }

    /**
     * Construtor parametrizado de Answer.
     *
     * @param user_id Identificador do user
     * @param post_id Identificador do post
     * @param parent_id Identificador da pergunta a que se refere
     * @param score Score da resposta
     * @param comment_count Número de comentários
     */
    public Answer(long user_id, long post_id, LocalDate pd, long parent_id, int score, int comment_count) {
        super(user_id, post_id, pd);
        this.parent_id = parent_id;
        this.score = score;
        this.comment_count = comment_count;
    }

    /**
     * Construtor de Cópia.
     *
     * @param a Resposta
     */
    public Answer(Answer a) {
        super(a);
        this.parent_id = a.getParentId();
        this.score = a.getScore();
        this.comment_count = a.getCommentCount();
    }

    /**
     * Método que devolve o id da pergunta a que a resposta pertence.
     *
     * @returns long - Identificador da pergunta a que a resposta pertence.
     */
    public long getParentId() {
        return parent_id;
    }

    /**
     * Método que estabelece o id da pergunta a que a resposta pertence.
     *
     * @param id Identificador da pergunta a que a resposta pertence.
     */
    public void setParentId(long id) {
        parent_id = id;
    }

    /**
     * Método que devolve o score da resposta
     *
     * @returns int - score
     */
    public int getScore() {
        return score;
    }

    /**
     * Método que estabelece o score da resposta
     *
     * @param score Score da resposta
     */
    public void setScore(int score) {
        this.score = score;
    }

    /**
     * Método que devolve o número de comentários da resposta.
     *
     * @returns int - número de comentários
     */
    public int getCommentCount() {
        return comment_count;
    }

    /**
     * Método que estabelece o número de comentários da resposta.
     *
     * @param comment_count o número de comentários da resposta.
     */
    public void setCommentCount(int comment_count) {
        this.comment_count = comment_count;
    }

    /**
     * Método que faz uma cópia de answer.
     * Para tal invoca o construtor de cópia.
     *
     * @return cópia de answer
     */
    public Answer clone() {
         return new Answer(this);
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

        Answer resposta = (Answer) object;
        return  (super.equals(resposta) && parent_id == resposta.getParentId()
                 && score == resposta.getScore() && comment_count == resposta.getCommentCount());
    }

    /**
     * Método que devolve a representação em String de Answer.
     *
     * @return String que representa uma resposta
     */
    public String toString() {
        return "Answer {" +
                super.toString() +
                ", ParentId = " + parent_id +
                ", Score = " + score +
                ", CommentCount = " + comment_count +
                "}";
    }
}
