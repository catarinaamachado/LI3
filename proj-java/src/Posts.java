
/**
 * Classe abstrata Posts
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

public abstract class Posts {
    private long user_id;
    private long post_id;

    public Posts() {
        user_id = 0;
        post_id = 0;
    }

    public Posts(long user_id, long post_id) {
        this.user_id = user_id;
        this.post_id = post_id;
    }

    public Posts(Posts p) {
        user_id = p.getUserId();
        post_id = p.getPostId();
    }

      /**
     * Função que devolve o id do user que deu a resposta.
     *
     * @returns long - Identificador do user que deu a resposta.
     */
    public long getUserId() {
        return user_id;
    }

      /**
     * Função que estabelece o id do user que deu a resposta.
     *
     * @param id Identificador do user que deu a resposta.
     */
    public void setUserId(long id) {
        user_id = id;
    }

      /**
     * Função que devolve o id da resposta.
     *
     * @returns long - Identificador da resposta.
     */
    public long getPostId() {
        return post_id;
    }

     /**
     * Função que estabelece o o id da resposta.
     *
     * @param id Identificador da resposta.
     */
    public void setPostId(long id) {
        post_id = id;
    }

     /**
     * Método que devolve a representação em String de Posts.
     *
     * @return String que representa um post
     */
    public String toString() {

        return "Posts{" +
                ", UserId = " + user_id +
                ", PostId = " + post_id +
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
}
