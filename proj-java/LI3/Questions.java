
/**
 * Escreva a descrição da classe Questions aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
public class Questions {
  private long post_id;
  //private LocalDate pd;
  private long user_id;
  private String title;
  private String tags;
  private int n_answers;
  private int n_answer_votes;
  //private List<Answers> answers;

  
  public Questions() {
        post_id = 0;
        user_id = 0;
        title = "";
        tags = "";
        n_answers = 0;
        n_answer_votes = 0;
    }
  
  public Questions(long post_id, long user_id, String title, String tags, int n_answers, int n_answer_votes) {
      this.post_id = post_id;
      this.user_id = user_id;
      this.title = title;
      this.tags = tags;
      this.n_answers = n_answers;
      this.n_answer_votes = n_answer_votes;
  }
  
  public Questions(Questions q) {
      this.post_id = q.getPostId();
      this.user_id = q.getUsertId();
      this.title = q.getTitle();
      this.tags = q.getTags();
      this.n_answers = q.getNAnswers();
      this.n_answer_votes = q.getNAnswerVotes();
  }

  /**
     * Função que devolve o id da pergunta.
     *
     * @returns long - Identificador da pergunta.
     */
    public long getPostId() {
      return post_id;
    }

  /**
     * Função que estabelece o o id da pergunta.
     *
     * @param id Identificador da pergunta.
     */
    public void setPostId(long id) {
      post_id = id;
    }
    
  /**
     * Função que devolve o id do utilizador.
     *
     * @returns long - Identificador do user.
     */
    public long getUsertId() {
      return user_id;
    }

  /**
     * Função que estabelece o o id do utilizador.
     *
     * @param id Identificador do utilizador.
     */
    public void setUserId(long id) {
      post_id = id;
    }
  
  /**
     * Função que devolve o título.
     *
     * @returns String - título.
     */
    public String getTitle() {
      return title;
    }

  /**
     * Função que estabelece o título.
     *
     * @param title Título.
     */
    public void setTitle(String title) {
      this.title = title;
    }  
    
  /**
     * Função que devolve as tags.
     *
     * @returns String - tags.
     */
    public String getTags() {
      return tags;
    }

  /**
     * Função que estabelece as tags.
     *
     * @param tags Tags.
     */
    public void setTags(String tags) {
      this.tags = tags;
    }  
  
  /**
     * Função que devolve o número de respostas de uma pergunta.
     *
     * @returns int - número de respostas.
     */
    public int getNAnswers() {
      return n_answers;
    }

  /**
     * Função que estabelece o número de respostas de uma pergunta.
     *
     * @param n_answers Número de respostas de uma pergunta.
     */
    public void setNAnswers(int n_answers) {
      this.n_answers = n_answers;
    } 
    
  /**
     * Função que devolve o número total de votos das respostas de uma pergunta.
     *
     * @returns int - número de votos das respostas.
     */
    public int getNAnswerVotes() {
      return n_answer_votes;
    }

  /**
     * Função que estabelece o número total de votos das respostas de uma pergunta.
     *
     * @param n_answers Número total de votos das respostas de uma pergunta.
     *
     */
    public void setNAnswerVotes(int n_answer_votes) {
      this.n_answer_votes = n_answer_votes;
    }  
  
  /**
     * Método que faz uma cópia de questions.
     * Para tal invoca o construtor de cópia.
     *
     * @return cópia de questions
     */
    public Questions clone() {
        return new Questions(this);
    }
    
  /**
     * Método que devolve a representação em String de Questions.
     *
     * @return String que representa uma question
     */
    public String toString() {
        return "Questions{" +
                ", PostId = " + post_id +
                ", UserId = " + user_id +
                ", Title = " + title +
                ", Tags = " + tags +
                ", Número de respostas = " + n_answers +
                ", Número total de votos das respostas = " + n_answer_votes +
                '}';
    }
    
  /**
    Método que determina se duas perguntas são iguais.
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
        
        Questions q = (Questions) object;
        return  (post_id == q.getPostId() && user_id == q.getUsertId() &&
                title.equals(q.getTitle()) && tags.equals(q.getTags()) &&
                n_answers == q.getNAnswers() && n_answer_votes == q.getNAnswerVotes());

    }
    
    
}