.PHONY: clean All

All:
	@echo "----------Building project:[ ArrayElementMode - Debug ]----------"
	@cd "ArrayElementMode" && "$(MAKE)" -f  "ArrayElementMode.mk"
clean:
	@echo "----------Cleaning project:[ ArrayElementMode - Debug ]----------"
	@cd "ArrayElementMode" && "$(MAKE)" -f  "ArrayElementMode.mk" clean
