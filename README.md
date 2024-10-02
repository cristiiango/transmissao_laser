# Transmissão de Dados via Laser com Arduino

## Descrição
Este projeto demonstra um sistema simples de transmissão de dados baseado em laser usando microcontroladores Arduino. Ele permite a comunicação serial entre duas placas Arduino (Uno e Nano) usando um módulo laser e um sensor de luz.

## Índice
- [Visão Geral](#visão-geral)
- [Componentes](#componentes)
- [Configuração](#configuração)
- [Como Funciona](#como-funciona)
- [Resultados](#resultados)
- [Limitações e Melhorias Futuras](#limitações-e-melhorias-futuras)
- [Contribuidores](#contribuidores)

## Visão Geral
Este projeto explora o uso da luz, especificamente laser, para transmissão de dados. Utiliza um Arduino Uno como transmissor e um Arduino Nano como receptor. O sistema modula os dados em pulsos de laser, que são então detectados e decodificados pelo receptor.

## Componentes
- Arduino Uno (Transmissor)
- Arduino Nano (Receptor)
- Módulo Laser HW-493
- Receptor de Laser ISO203
- Display LCD 16x2 com interface I2C
- Jumpers e resistores
- Cabo USB

## Configuração
1. Conecte o módulo laser ao Arduino Uno (Pino 7).
2. Conecte o receptor de laser ao Arduino Nano (Pino 7).
3. Conecte o display LCD ao Arduino Nano usando I2C.
4. Faça o upload do código do transmissor para o Arduino Uno.
5. Faça o upload do código do receptor para o Arduino Nano.
6. Alinhe o módulo laser com o receptor.

## Como Funciona
1. O Arduino Uno lê a entrada do monitor serial.
2. Ele converte a entrada em pulsos de laser usando comunicação serial.
3. O sensor de luz do Arduino Nano detecta esses pulsos.
4. Os dados recebidos são decodificados e exibidos na tela LCD.

## Resultados
- Transmissão bem-sucedida de mensagens curtas com 95% de precisão.
- Taxa de transmissão de 4800 bps, suficiente para mensagens de texto curtas.
- Tempo médio de transmissão e exibição de cerca de 5 segundos por mensagem.
- Forte dependência do alinhamento adequado entre laser e sensor.
- Sensibilidade às condições de luz ambiente.

## Limitações e Melhorias Futuras
- Limitado pela taxa de baud (4800 bps) e capacidades de processamento do Arduino.
- Requer linha de visão direta e alinhamento preciso.
- Sensível a fatores ambientais como luz ambiente.
- Trabalhos futuros poderiam focar no aumento da velocidade de transmissão e na melhoria da robustez contra interferências ambientais.

## Contribuidores
- André Lucas Cota de Sá
- Cristian Filipe Gomes de Brito
- Geovana Souza dos Anjos
- Lucas de Paula Portuence

Este projeto foi desenvolvido como parte de um curso na Universidade Federal de Ouro Preto (UFOP), sob a orientação do Professor Rodrigo Augusto Ricco.
