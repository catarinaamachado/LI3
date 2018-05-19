
/**
 * Escreva a descrição da classe Answers aqui.
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

  public Answers() {
      super();
      parent_id = 0;
      score = 0;
      comment_count = 0;
    }

  public Answers(long user_id, long post_id, long parent_id, int score, int comment_count) {
    super(user_id, post_id);
    this.parent_id = parent_id;
    this.score = score;
    this.comment_count = comment_count;
    }

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

  //TODO equals e toString
}
