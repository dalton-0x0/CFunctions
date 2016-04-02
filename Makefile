.PHONY: clean All

All:
	@echo "----------Building project:[ CountGrades - Debug ]----------"
	@cd "CountGrades" && "$(MAKE)" -f  "CountGrades.mk"
clean:
	@echo "----------Cleaning project:[ CountGrades - Debug ]----------"
	@cd "CountGrades" && "$(MAKE)" -f  "CountGrades.mk" clean
