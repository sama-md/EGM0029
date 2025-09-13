# EGM0029 - Sistemas Embarcados para Controle e Automação

[![Main](https://img.shields.io/badge/main%20language-PT-blue)](/../../)

Este repositório contém o material de suporte utilizado na componente curricular Sistemas Embarcados para Controle e Automação do curso de Pós-Graduação em Engenharia Mecatrônica da Universidade Federal do Rio Grande do Norte (UFRN).

### Conteúdo

**ESP32** introdução aos periféricos do ESP32-S3 em C.

- Código fonte para piscar um led na porta GPIO5 ([io_wpin.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/io_wpin.c))
- Código fonte para acionar um led na porta GPIO5 a partir da leitura do nível lógico da porta GPIO4 ([io_rpin_wpin.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/io_rpin_wpin.c))
- Código fonte para acionar um led na porta GPIO5 a partir da leitura do nível analógico na porta GPIO1 ([adc_io_wpin.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/adc_io_wpin.c))
- Código fonte para piscar um led na porta GPIO5 controlado pelo GPTimer ([gptimer_io_wpin.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/gptimer_io_wpin.c))
- Código fonte para aplicar um sinal pwm na porta GPIO5 ([pwm_io_wpin.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/pwm_io_wpin.c))
- Código fonte para contar o número de pulsos na porta GPIO5 ([pcnt_prn.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/pcnt_prn.c))
- Código fonte para piscar um led na porta GPIO5 a partir da interrupção de pulso no GPIO 10 ([io_wpin_button_isr.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/io_wpin_button_isr.c))
- Código fonte para piscar um led na porta GPIO5 a partir da interrupção de timer ([io_wpin_timer_isr.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/io_wpin_timer_isr.c))

**ESP32** introdução ao ESP-IDF FreeRTOS no ESP32-S3 em C.
- Código fonte para cria task ([rtos_io_wpin.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_io_wpin.c.c))
- Código fonte para criar fila ([rtos_queue_prn.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_queue_prn.c.c))
- Código fonte para criar fila (mailbox) ([rtos_queue_mailbox_prn.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_queue_mailbox_prn.c.c))
- Código fonte para criar semáforo binário ([rtos_semphr_binary.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_semphr_binary.c.c))
- Código fonte para criar semáforo contador ([rtos_semphr_count.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_semphr_count.c.c))
- Código fonte para criar mutex ([rtos_semphr_mutex.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_semphr_mutex.c.c))
- Código fonte para criar notificação direct-to-task ([rtos_notify.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_notify.c.c))
- Código fonte para notificação direct-to-task com mensagem ([rtos_notify_msg.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_notify_msg.c.c))
- Código fonte para criar stream da dados ([rtos_stream.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_stream.c.c))
- Código fonte para criar buffer de mensagem ([rtos_message_buffer.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_message_buffer.c.c))
- Código fonte para criar grupo de eventos ([rtos_event_group.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_event_group.c.c))
- Código fonte para criar timer de software ([rtos_soft_timer.c](https://github.com/sama-md/EGM0029/blob/main/perifericos/rtos_soft_timer.c.c))

---
### Licença

Shield : [![License: CC BY-NC-ND 4.0](https://img.shields.io/badge/License-CC%20BY--NC--ND%204.0-lightgrey)](https://creativecommons.org/licenses/by-nc-nd/4.0/)

Esta obra tem a [licença Creative Commons Atribuição-NãoComercial-SemDerivações 4.0 Internacional](https://creativecommons.org/licenses/by-nc-nd/4.0/deed.pt_BR).

[![CC BY-NC-ND 4.0](https://licensebuttons.net/l/by-nc-nd/4.0/88x31.png)](https://creativecommons.org/licenses/by-nc-nd/4.0/deed.pt_BR)

 
