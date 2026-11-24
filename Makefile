# Makefile do Aprendendo C++
#
#   make exemplos      compila todos os exemplos
#   make exercicios    compila todos os exercícios
#   make test          compila e roda os testes
#   make test MODULO=03  roda só o módulo 03
#   make limpar        apaga a pasta build/

CXX      ?= g++
# -Wno-unused-parameter: os exercícios ainda não resolvidos têm parâmetros sem uso.
CXXFLAGS ?= -std=c++20 -Wall -Wextra -Wno-unused-parameter -O2
INCLUDES := -Iinclude

FILTRO   := $(if $(MODULO),$(wildcard modulos/$(MODULO)-*),$(wildcard modulos/*))

EXEMPLOS_SRC := $(shell find $(FILTRO) -path '*/exemplos/*.cpp' 2>/dev/null | sort)
TESTES_SRC   := $(shell find $(FILTRO) -path '*/exercicios/*.cpp' 2>/dev/null | sort)

EXEMPLOS_BIN := $(patsubst modulos/%.cpp,build/%.exe,$(EXEMPLOS_SRC))
TESTES_BIN   := $(patsubst modulos/%.cpp,build/%.exe,$(TESTES_SRC))

.PHONY: all exemplos exercicios test limpar ajuda

all: exemplos exercicios

## Compila cada exemplo em build/<modulo>/exemplos/<nome>.exe
build/%.exe: modulos/%.cpp
	@mkdir -p $(dir $@)
	@printf '  compilando %s\n' '$<'
	@$(CXX) $(CXXFLAGS) $(INCLUDES) '$<' -o '$@'

exemplos: $(EXEMPLOS_BIN)
	@echo ""
	@echo "Exemplos compilados em build/. Rode com: ./build/<modulo>/exemplos/<nome>.exe"

exercicios: $(TESTES_BIN)
	@echo ""
	@echo "Exercícios compilados em build/. Teste com: make test"

test: $(TESTES_BIN)
	@echo ""
	@echo "══════════════════════════════════════════════════"
	@echo " Rodando exercícios $(if $(MODULO),do módulo $(MODULO),de todos os módulos)"
	@echo "══════════════════════════════════════════════════"
	@total=0; ok=0; \
	for bin in $(TESTES_BIN); do \
		total=$$((total + 1)); \
		if ./$$bin; then ok=$$((ok + 1)); fi; \
	done; \
	echo ""; \
	echo "──────────────────────────────────────────────────"; \
	echo " Resultado: $$ok de $$total exercícios concluídos"; \
	if [ $$ok -eq $$total ]; then \
		echo " Tudo certo! 🎉"; \
	else \
		echo " Continue tentando: abra o .cpp e resolva os TODOs."; \
	fi

limpar:
	rm -rf build

ajuda:
	@sed -n '2,9p' Makefile
