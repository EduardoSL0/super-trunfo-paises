# Super Trunfo Países - Nível Mestre 🏆

Desafio final do Super Trunfo em C, implementando comparações avançadas com múltiplos atributos, menus dinâmicos e lógica de decisão.

---

## 📋 Sobre o Projeto

Projeto em C onde duas cartas de países (Brasil e Japão) são comparadas com base em dois atributos escolhidos pelo usuário.  
O vencedor é definido pela soma dos atributos, seguindo regras específicas.

---

## 🎯 Funcionalidades

- Comparação com dois atributos  
- Menu dinâmico (não permite repetir)  
- Soma dos atributos  
- Tratamento de empate  
- Uso de operador ternário  
- Validação de entrada  

---

## 🃏 Cartas

| Atributo | Brasil | Japão |
|----------|--------|-------|
| População | 214.000.000 | 125.000.000 |
| Área (km²) | 8.515.767 | 377.975 |
| PIB | 1,8 | 5,0 |
| Pontos Turísticos | 50 | 80 |
| Densidade | 25,1 | 330,0 |
| IDH | 0,765 | 0,919 |

> Regra: na densidade, o menor valor vence.

---

## 🚀 Execução

**Como executar:**
```bash
gcc main.c -o jogo
./jogo
