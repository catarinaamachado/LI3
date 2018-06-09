package common;

/**
 * Classe abstrata Posts.
 * Refere-se tanto a perguntas como a respostas.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.time.LocalDate;

public abstract class Posts implements Comparable<Posts> {
    private long user_id;
    private long post_id;
    private LocalDate pd;

    /**
     * Construtor por omissão de Posts.
     */
    public Posts() {
        this.user_id = 0;
        this.post_id = 0;
        this.pd = LocalDate.MIN;
    }

    /**
     * Construtor parametrizado de Posts.
     *
     * @param user_id Identificador do user
     * @param post_id Identificador do post
     * @param pd data do post
     */
    public Posts(long user_id, long post_id, LocalDate pd) {
        this.user_id = user_id;
        this.post_id = post_id;
        this.pd = pd;
    }

    /**
     * Construtor de Cópia.
     *
     * @param p Post a ser replicado
     */
    public Posts(Posts p) {
        this.user_id = p.getUserId();
        this.post_id = p.getPostId();
        this.pd = p.getPd();
    }

    /**
     * Método que devolve o id do user que deu a pergunta ou a resposta.
     *
     * @returns long - Identificador do user que deu a pergunta/ resposta.
     */
    public long getUserId() {
        return user_id;
    }

    /**
     * Método que estabelece o id do user que deu a pergunta ou a resposta.
     *
     * @param id Identificador do user que deu a pergunta/ resposta.
     */
    public void setUserId(long id) {
        user_id = id;
    }

    /**
     * Método que devolve o id da pergunta ou da resposta.
     *
     * @returns long - Identificador do post.
     */
    public long getPostId() {
        return post_id;
    }

    /**
     * Método que estabelece o o id da pergunta ou da resposta.
     *
     * @param id Identificador do post.
     */
    public void setPostId(long id) {
        post_id = id;
    }

    /**
     * Método que devolve data do post
     *
     * @return Data do post
     */
    public LocalDate getPd() {
        return pd;
    }

    /**
     * Método que atualiza data do post
     *
     * @param pd Data do post
     */
    public void setPd(LocalDate pd) {
        this.pd = pd;
    }

    /**
     * Método que devolve a representação em String de Posts.
     *
     * @return String que representa um post
     */
    public String toString() {
        return "Posts{" +
                " UserId = " + user_id +
                ", PostId = " + post_id +
                ", Date = " + pd +
                '}';
    }

    /**
     * Método que determina se dois posts são iguais.
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

        Posts post = (Posts) object;
        return  (post_id == post.getPostId() && user_id == post.getUserId());
    }

    public abstract Posts clone();

    public int compareTo(Posts a) {
        if(pd.isAfter(a.getPd()))
            return -1;
        if(pd.isBefore(a.getPd()))
            return 1;
        return 0;
    }
}
