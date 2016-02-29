.PHONY: clean All

All:
	@echo "----------Building project:[ DomoUI - Debug ]----------"
	@cd "DomoUI" && "$(MAKE)" -f  "DomoUI.mk"
clean:
	@echo "----------Cleaning project:[ DomoUI - Debug ]----------"
	@cd "DomoUI" && "$(MAKE)" -f  "DomoUI.mk" clean
