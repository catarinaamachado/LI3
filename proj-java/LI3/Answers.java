
/**
 * Escreva a descrição da classe Answers aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
public class Answers
{
  private long user_id;
  private long answer_id;
  private long parent_id; // a que pergunta pertence
  private int score;
  private int comment_count; //número de comentários recebidos pela resposta (query 10)

  public Answers() {
      user_id = 0;
      answer_id = 0;
      parent_id = 0;
      score = 0;
      comment_count = 0;
    }
  
  public Answers(long user_id, long answer_id, long parent_id, int score, int comment_count) {
    this.user_id = user_id;
    this.answer_id = answer_id;
    this.parent_id = parent_id;
    this.score = score;
    this.comment_count = comment_count;
    } 
    
  public Answers(Answers a) {
      this.user_id = a.getAUserId();
      this.answer_id = a.getAnswerId();
      this.parent_id = a.getParentId();
      this.score = a.getScore();
      this.comment_count = a.getCommentCount();
    }
    
  /**
     * Função que devolve o id do user que deu a resposta.
     *
     * @returns long - Identificador do user que deu a resposta.
     */
    public long getAUserId() {
      return user_id;
    }

  /**
     * Função que estabelece o id do user que deu a resposta.
     *
     * @param id Identificador do user que deu a resposta.
     */
    public void setAUserId(long id) {
      user_id = id;
    }
    
  /**
     * Função que devolve o id da resposta.
     *
     * @returns long - Identificador da resposta.
     */
    public long getAnswerId() {
      return answer_id;
    }

  /**
     * Função que estabelece o o id da resposta.
     *
     * @param id Identificador da resposta.
     */
    public void setAnswerId(long id) {
      answer_id = id;
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
}
