package common;

/**
 * Estrutura de dados relativa aos dias.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180609
 */

import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class Day {
    private int n_questions;
    private int n_answers;
    private List<Question> questions; 
    private List<Answer> answers; 

    /**
     * Construtor por omissão de Day.
     */
    public Day() {
        this.n_questions = 0;
        this.n_answers = 0;
        this.questions = new ArrayList<>();
        this.answers = new ArrayList<>();
    }
    
    /**
     * Construtor parametrizado de Day.
     *
     * @param n_questions Número de perguntas
     * @param n_answers Número de respostas
     * @param questions Perguntas do dia
     * @param answers Respostas do dia
     */
    public Day(int n_questions, int n_answers,
                        List<Question> questions, List<Answer> answers) {
        this.n_questions = n_questions;
        this.n_answers = n_answers;
        setQuestions(questions);
        setAnswers(answers);
      }

    /**
     * Construtor de Cópia.
     *
     * @param d Dia 
     */
    public Day(Day d) {
        this.n_questions = d.getN_questions();
        this.n_answers = d.getN_answers();
        this.questions = d.getQuestions();
        this.answers = d.getAnswers();
    }
    
    /**
     * Método que devolve o número de perguntas
     * efetuadas na data.
     *
     * @returns int - número de perguntas.
     */
    public int getN_questions() {
        return this.n_questions;
    }    

    /**
     * Método que estabelece o número de perguntas da data.
     *
     * @param n_questions número de perguntas.
     */
    public void setN_questions(int n_questions) {
        this.n_questions = n_questions;
    }
        
    /**
     * Método que devolve o número de respostas
     * efetuadas na data.
     *
     * @returns int - número de respostas.
     */
    public int getN_answers() {
        return this.n_answers;
    }

    /**
     * Método que estabelece o número de respostas da data.
     *
     * @param n_answers número de respostas.
     */
    public void setN_answers(int n_answers) {
        this.n_answers = n_answers;
    }
    
    /**
     * Método que devolve as perguntas da data.
     *
     * @returns List<Question> - lista das perguntas.
     */
    public List<Question> getQuestions() {
        return questions.stream().map(Question :: clone).
                  collect(Collectors.toCollection(ArrayList::new));
    }
    
    /**
     * Método que estabelece as perguntas feitos num determinado dia.
     *
     * @param perguntas Lista com as perguntas.
     */
    public void setQuestions(List<Question> perguntas) {
        this.questions = perguntas.stream().map(Question :: clone).
                        collect(Collectors.toCollection(ArrayList::new));
    }  
        
    /**
     * Método que devolve as respostas da data.
     *
     * @returns List<Answer> - lista das respostas.
     */
    public List<Answer> getAnswers() {
        return answers.stream().map(Answer :: clone).
                  collect(Collectors.toCollection(ArrayList::new));
    }
  
    /**
     * Método que estabelece as respostas feitos num determinado dia.
     *
     * @param respostas Lista com as respostas.
     */
    public void setAnswers(List<Answer> respostas) {
        this.answers = respostas.stream().map(Answer :: clone).
                        collect(Collectors.toCollection(ArrayList::new));
    }

    /**
     * Método que faz uma cópia de day.
     * Para tal invoca o construtor de cópia.
     *
     * @return cópia de day
     */    
    public Day clone() {
         return new Day(this);
    }    
        
    /**
     * Método que determina se dois dias são iguais.
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

        Day dia = (Day) object;
        return  (n_questions == dia.getN_questions() && n_answers == dia.getN_answers() &&
                 questions.equals(dia.getQuestions()) && answers.equals(dia.getAnswers()));
    }    

    /**
     * Método que devolve a representação em String de Day.
     *
     * @return String que representa um dia.
     */
    public String toString() {
        StringBuilder AnswersList = new StringBuilder();
        StringBuilder QuestionsList = new StringBuilder();
        
        for (Answer resposta: answers) {      
            AnswersList.append(resposta.toString());
            AnswersList.append(" "); 
        }  
        
        for (Question pergunta: questions) {      
            AnswersList.append(pergunta.toString());
            AnswersList.append(" "); 
        }  
        
        return "Day {" +
                " Número de perguntas = " + n_questions +
                ", Número de respostas = " + n_answers +
                ", Questions =" + QuestionsList.toString() +
                ", Answers =" + AnswersList.toString() +
                "}";
    }   
    
    /**
     * Método que adiciona uma pergunta e incrementa o
     * número de perguntas efetuadas na data.
     *
     * @param pergunta Pergunta
     */
    public void addQuestion(Question pergunta) {
        this.questions.add(pergunta.clone());
        this.n_questions++;
    }  
    
    /**
     * Método que adiciona uma resposta e incrementa o
     * número de respostas efetuadas na data.
     *
     * @param resposta Resposta
     */
    public void addAnswer(Answer resposta) {
        this.answers.add(resposta.clone());
        this.n_answers++;
    }      
    
}
