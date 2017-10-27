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
pop_star_friends.lss \

FLASH_IMAGE += \
pop_star_friends.hex \

EEPROM_IMAGE += \
pop_star_friends.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: pop_star_friends.elf secondary-outputs

# Tool invocations
pop_star_friends.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,pop_star_friends.map -mmcu=atmega8 -o "pop_star_friends.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

pop_star_friends.lss: pop_star_friends.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S pop_star_friends.elf  >"pop_star_friends.lss"
	@echo 'Finished building: $@'
	@echo ' '

pop_star_friends.hex: pop_star_friends.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex pop_star_friends.elf  "pop_star_friends.hex"
	@echo 'Finished building: $@'
	@echo ' '

pop_star_friends.eep: pop_star_friends.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex pop_star_friends.elf  "pop_star_friends.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: pop_star_friends.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 pop_star_friends.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) pop_star_friends.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
