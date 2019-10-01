/**
  Roda de luzes
 
  @author Pedro Serer <pedrotiserer@hotmail.com>
  @version 1.0.0
*/
 
int leds[4]        = {13, 12, 11, 10};
int botaoVermelho  = 7;
int botaoAzul      = 6;
int botao1         = 0;
int botao2         = 0;
int i;
 
/**
  As variáveis das portas usadas no arduíno sendo percorridas
  pelo vetor, então os LED's de entrada estão no vetor.
*/
void setup()
{
  for(i=0; i<leds[i]; i++){
    pinMode(leds[i], OUTPUT);
  }
 
  pinMode(botaoVermelho, INPUT);
  pinMode(botaoAzul, INPUT);
}
 
/**
  Pega o valor do botão de ligar(vermelho) e verifica se foi pressionado,
  então se a condição for verdadeira inicia um loop infinito parando o segmento
  da função LOOP(). Ele percorre vetores para determinar quais LED's estarão
  acesos. No inicio do looping verifico sempre se o botão desligar(azul) foi
  pressionado, este sendo pressionado sai do laço retornando ao inicio da
  função principal apagando os LED's.
*/
 
void loop()
{
  botao1 = digitalRead(botaoVermelho);
 
  if(botao1 == 0)
  {
    for(;;)
    {
      botao2 = digitalRead(botaoAzul);
      if(botao2 == 0){break;}
 
      for(i=0; i<leds[i]; i++)
      {
        digitalWrite(leds[i], 1);
        delay(100);
      }
 
      for(i=0; i<leds[i]; i++)
      {
        digitalWrite(leds[i], 0);
        delay(100);
      }
    }
  }
}
