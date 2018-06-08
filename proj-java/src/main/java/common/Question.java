package common;

import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;


/**
 * Escreva a descrição da classe Questions aqui.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

public class Question extends Posts {
    //private LocalDate pd;
    private String title;
    private String tags;
    private int n_answers;
    private int n_answer_votes;
    private List<Answers> answers; //TODO clones desta variavel

    public Question() {
        super();
        title = "";
        tags = "";
        n_answers = 0;
        n_answer_votes = 0;
        answers = new ArrayList();
    }

    public Question(long post_id, long user_id, String title, String tags, 
                    int n_answers, int n_answer_votes, List answers) {
        super(post_id, user_id);
        this.title = title;
        this.tags = tags;
        this.n_answers = n_answers;
        this.n_answer_votes = n_answer_votes;
        setAnswersList(answers);
      }

    public Question(Question q) {
        super(q);
        this.title = q.getTitle();
        this.tags = q.getTags();
        this.n_answers = q.getNAnswers();
        this.n_answer_votes = q.getNAnswerVotes();
        this.answers = q.getAnswersList();
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
     * Função que devolve as respostas de uma pergunta.
     *
     * @returns List<Answers> - lista das respostas.
     */
    public List<Answers> getAnswersList() {
        return answers.stream().map(Answers :: clone).
                  collect(Collectors.toCollection(ArrayList::new));
    }
  
    /**
     * Função que estabelece as respostas de uma pergunta.
     *
     * @param respostas Lista com as respostas de uma pergunta.
     *
     */
    public void setAnswersList(List<Answers> respostas) {
        this.answers = respostas.stream().map(Answers :: clone).
                        collect(Collectors.toCollection(ArrayList::new));
    }
    
    /**
     * Método que faz uma cópia de questions.
     * Para tal invoca o construtor de cópia.
     *
     * @return cópia de questions
     */
    public Question clone() {
        return new Question(this);
    }

    /**
     * Método que devolve a representação em String de Questions.
     *
     * @return String que representa uma question
     */
    public String toString() {
        StringBuilder AnswersList = new StringBuilder();

            for (Answers resposta: answers) {      
                 AnswersList.append(resposta.toString());
                 AnswersList.append(" "); 
            }
            
     
        return "Question{" +
                super.toString() +
                ", Title = " + title +
                ", Tags = " + tags +
                ", Número de respostas = " + n_answers +
                ", Número total de votos das respostas = " + n_answer_votes +
                ", Answers =" + AnswersList.toString() +
                '}';
    }

     /**
     * Método que determina se duas perguntas são iguais.
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

        Question q = (Question) object;
        return  (super.equals(q) &&
                title.equals(q.getTitle()) && tags.equals(q.getTags()) &&
                n_answers == q.getNAnswers() && n_answer_votes == q.getNAnswerVotes());
    }
    
    /**
     * Método que adiciona uma resposta à AnswersList.
     *
     * @param umaAnswer uma resposta.
     *
     */
    public void addAnswertoAnswersList(Answers umaAnswer) {
        answers.add(umaAnswer);
    }
    
   
    
}