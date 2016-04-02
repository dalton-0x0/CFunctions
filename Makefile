.PHONY: clean All

All:
	@echo "----------Building project:[ BlackJackCalc - Debug ]----------"
	@cd "BlackJackCalc" && "$(MAKE)" -f  "BlackJackCalc.mk"
clean:
	@echo "----------Cleaning project:[ BlackJackCalc - Debug ]----------"
	@cd "BlackJackCalc" && "$(MAKE)" -f  "BlackJackCalc.mk" clean
