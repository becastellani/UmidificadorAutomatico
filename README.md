<h1 align="center">Controle de Umidade</h1>

<p align="center">
  <img src="images/project-preview.png" alt="Preview" width="500">
</p>

<p align="center">Um sistema de controle de umidade utilizando Arduino, sensor DHT11, display LCD e relé.</p>

## Descrição

Este projeto consiste em um sistema de controle de umidade que utiliza um Arduino, um sensor DHT11 para medição da umidade, um display LCD para exibição das informações e um relé para controlar um dispositivo externo, como um umidificador ou desumidificador.

O código monitora a umidade ambiente e aciona o relé com base em um limite de umidade configurável. O display LCD exibe a umidade atual e o estado do sistema. Além disso, há um botão de desligar que permite desativar completamente o sistema.

## Funcionalidades

- Medição da umidade ambiente utilizando o sensor DHT11
- Controle do relé para ligar ou desligar um dispositivo externo
- Exibição da umidade e status no display LCD
- Botão de desligar para desativar completamente o sistema

## Componentes Utilizados

- Arduino Uno
- Sensor DHT11
- Display LCD 16x2
- Relé
- Botão de desligar
- Resistores e cabos de conexão

## Diagrama de Conexões

<p align="center">
  <img src="images/connection-diagram.png" alt="Diagrama de Conexões" width="600">
</p>

## Instalação e Uso

1. Clone este repositório em sua máquina local.
2. Conecte os componentes de acordo com o diagrama de conexões.
3. Carregue o código `controle_umidade.ino` para o Arduino utilizando a IDE do Arduino.
4. Execute o programa e observe a medição da umidade e o controle do relé.

## Contribuição

Contribuições são bem-vindas! Para contribuir com o projeto, siga estas etapas:

1. Faça um fork deste repositório.
2. Crie uma nova branch com sua contribuição: `git checkout -b minha-contribuicao`.
3. Faça as alterações desejadas e commit: `git commit -m 'Minha Contribuição'`.
4. Push para a branch: `git push origin minha-contribuicao`.
5. Abra um pull request descrevendo suas alterações.
