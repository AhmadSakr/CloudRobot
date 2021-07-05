################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FINAL_PRO.lss \

FLASH_IMAGE += \
FINAL_PRO.hex \

EEPROM_IMAGE += \
FINAL_PRO.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: FINAL_PRO.elf secondary-outputs

# Tool invocations
FINAL_PRO.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FINAL_PRO.map -mmcu=atmega32 -o "FINAL_PRO.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FINAL_PRO.lss: FINAL_PRO.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FINAL_PRO.elf  >"FINAL_PRO.lss"
	@echo 'Finished building: $@'
	@echo ' '

FINAL_PRO.hex: FINAL_PRO.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FINAL_PRO.elf  "FINAL_PRO.hex"
	@echo 'Finished building: $@'
	@echo ' '

FINAL_PRO.eep: FINAL_PRO.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex FINAL_PRO.elf  "FINAL_PRO.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FINAL_PRO.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FINAL_PRO.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FINAL_PRO.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
