.PHONY: clean All

All:
	@echo "----------Building project:[ Exponent - Debug ]----------"
	@cd "Exponent" && "$(MAKE)" -f  "Exponent.mk"
clean:
	@echo "----------Cleaning project:[ Exponent - Debug ]----------"
	@cd "Exponent" && "$(MAKE)" -f  "Exponent.mk" clean
