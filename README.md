# GS2semestreIOT

## Video Pitch
https://www.youtube.com/watch?v=oJxDAb2kljA

## Participantes
<ul>
  <li> Caio Alves de Souza  -  RM94372 </li>
  <li> Kamilla de Lima      -  RM96112 </li>
  <li> Victor Mendes        -  RM92843 </li>
  <li> Vinicius Mendes      -  RM94375 </li>
  <li> Wesly Marques        -  RM93470 </li>
</ul>

## Resumo
Termômetro IoT com ESP32 monitora a temperatura do paciente. LED azul indica temperatura normal, LED vermelha alerta febre.

Objetivo:
O projeto visa criar um dispositivo de medição de temperatura que se conecta à Internet, capaz de monitorar a temperatura de um paciente de forma contínua e fornecer indicações visuais imediatas com base nos valores medidos.

## Componentes Principais:

ESP32: Placa de desenvolvimento utilizada para processamento e conexão Wi-Fi.
Sensor de Temperatura: Sensor preciso para capturar a temperatura corporal do paciente.
LED Azul e LED Vermelha: Indicadores visuais que acendem conforme a faixa de temperatura detectada.
Plataforma IoT ou Servidor na Nuvem: Para armazenamento e gerenciamento dos dados de temperatura.
Funcionamento:

Captura de Dados: O sensor de temperatura está conectado ao ESP32, que coleta os dados de temperatura do paciente em intervalos regulares.

Processamento e Comparação: O ESP32 processa os dados capturados e compara a temperatura com um limite predefinido (38 graus Celsius, no caso deste projeto).

Decisão e Feedback Visual: Se a temperatura estiver abaixo de 38 graus, a LED azul é acionada para indicar que a temperatura está dentro da faixa normal. Caso a temperatura esteja acima de 38 graus, a LED vermelha é ativada para alertar sobre a febre.

Conexão com a IoT: O ESP32 envia os dados da temperatura para uma plataforma IoT ou um servidor na nuvem para um registro histórico e possíveis análises posteriores.

## Benefícios:

Monitoramento Contínuo: Oferece um monitoramento constante da temperatura do paciente.
Indicação Visual Simples: As LEDs coloridas facilitam a compreensão dos valores de temperatura.
Registro de Dados: Armazenamento dos dados na nuvem permite análises detalhadas e histórico de temperatura.
Aplicações Potenciais:

Uso Doméstico: Monitoramento de temperatura de membros da família.
Ambientes Médicos: Hospitais, clínicas e unidades de saúde para monitorar pacientes.
Considerações Finais:
Este projeto combina hardware e conectividade para criar um dispositivo simples, mas eficaz, para monitorar a temperatura corporal de maneira contínua e fornecer feedback visual imediato, facilitando a detecção precoce de febres ou variações significativas na temperatura do paciente.

# Para replicar
Abra o link https://wokwi.com/projects/382046934554165249 em um navegador web.

Identificar o código: Localize o código-fonte ou a seção onde a variável myWriteAPIKey está definida.

Encontrar a variável myWriteAPIKey: 
const char * myWriteAPIKey = "SUA_CHAVE_API_AQUI";
Substituir pela sua chave: Substitua "SUA_CHAVE_API_AQUI" pela sua chave correta. Certifique-se de manter as aspas e inserir exatamente a chave necessária para a API de escrita.

Salvar as alterações: Após a substituição, salve as alterações no código.

Carregar o código no ESP32: Use a IDE do Arduino ou a ferramenta adequada para carregar o código atualizado no ESP32.

Esses passos devem permitir que você atualize a chave da API no código do ESP32 e utilize a plataforma ou serviço correspondente para o monitoramento da temperatura conforme o projeto proposto.
