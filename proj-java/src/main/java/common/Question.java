package common;

/**
 * Estrutura de dados relativa às perguntas.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.time.LocalDate;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class Question extends Posts {
    private String title;
    private String tags;
    private int n_answers;
    private int n_answer_votes;
    private List<Answer> answers;

    /**
     * Construtor por omissão de Question.
     */
    public Question() {
        super(0, 0, LocalDate.MIN, 1);
        this.title = "";
        this.tags = "";
        this.n_answers = 0;
        this.n_answer_votes = 0;
        this.answers = new ArrayList<>();
    }

    /**
     * Construtor parametrizado de Question.
     *
     * @param post_id Número identificador do post
     * @param user_id Número identificador do user
     * @param title Título da pergunta
     * @param tags Tags da pergunta
     * @param n_answers Número de respostas
     * @param n_answer_votes Número total de votos das respostas
     * @param answers Respostas da pergunta
     */
    public Question(long post_id, long user_id, LocalDate pd, String title,
            String tags, int n_answers, int n_answer_votes, List answers) {
        super(post_id, user_id, pd, 1);
        this.title = title;
        this.tags = tags;
        this.n_answers = n_answers;
        this.n_answer_votes = n_answer_votes;
        setAnswers(answers);
      }

    /**
     * Construtor de Cópia.
     *
     * @param q Pergunta
     */
    public Question(Question q) {
        super(q);
        this.title = q.getTitle();
        this.tags = q.getTags();
        this.n_answers = q.getNAnswers();
        this.n_answer_votes = q.getNAnswerVotes();
        this.answers = q.getAnswers();
    }

    /**
     * Método que devolve o título.
     *
     * @returns String - título.
     */
    public String getTitle() {
        return title;
    }

    /**
     * Método que estabelece o título.
     *
     * @param title Título.
     */
    public void setTitle(String title) {
        this.title = title;
    }

    /**
     * Método que devolve as tags.
     *
     * @returns String - tags.
     */
    public String getTags() {
        return tags;
    }

    /**
     * Método que estabelece as tags.
     *
     * @param tags Tags.
     */
    public void setTags(String tags) {
        this.tags = tags;
    }

    /**
     * Método que devolve o número de respostas de uma pergunta.
     *
     * @returns int - número de respostas.
     */
    public int getNAnswers() {
        return n_answers;
    }

    /**
     * Método que estabelece o número de respostas de uma pergunta.
     *
     * @param n_answers Número de respostas de uma pergunta.
     */
    public void setNAnswers(int n_answers) {
        this.n_answers = n_answers;
    }

    /**
     * Método que devolve o número total de votos das respostas de uma pergunta.
     *
     * @returns int - número de votos das respostas.
     */
    public int getNAnswerVotes() {
        return n_answer_votes;
    }

    /**
     * Método que estabelece o número total de votos das respostas de uma pergunta.
     *
     * @param n_answer_votes Número total de votos das respostas de uma pergunta.
     */
    public void setNAnswerVotes(int n_answer_votes) {
        this.n_answer_votes = n_answer_votes;
    }

    /**
     * Método que devolve as respostas de uma pergunta.
     *
     * @returns List<Answer> - lista das respostas.
     */
    public List<Answer> getAnswers() {
        return answers.stream().map(Answer :: clone).
                  collect(Collectors.toCollection(ArrayList::new));
    }

    /**
     * Método que estabelece as respostas de uma pergunta.
     *
     * @param respostas Lista com as respostas de uma pergunta.
     */
    public void setAnswers(List<Answer> respostas) {
        this.answers = respostas.stream().map(Answer :: clone).
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
     * Método que devolve a representação em String de Question.
     *
     * @return String que representa uma pergunta
     */
    public String toString() {
        StringBuilder AnswersList = new StringBuilder();

        for (Answer resposta: answers) {
            AnswersList.append(resposta.toString());
            AnswersList.append(" ");
        }

        return "Question {" +
                super.toString() +
                ", Title = " + title +
                ", Tags = " + tags +
                ", Número de respostas = " + n_answers +
                ", Número total de votos das respostas = " + n_answer_votes +
                ", Answers =" + AnswersList.toString() +
                "}";
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
                n_answers == q.getNAnswers() && n_answer_votes == q.getNAnswerVotes() &&
                answers.equals(q.getAnswers()));
    }

    /**
     * Método que adiciona uma resposta à AnswersList.
     *
     * @param umaAnswer uma resposta.
     */
    public void addAnswertoAnswersList(Answer umaAnswer) {
        answers.add(umaAnswer);
    }
}
