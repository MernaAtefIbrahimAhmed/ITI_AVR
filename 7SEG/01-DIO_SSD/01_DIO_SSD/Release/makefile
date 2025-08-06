################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/SSD/subdir.mk
-include APP/subdir.mk
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
01_DIO_SSD.lss \

FLASH_IMAGE += \
01_DIO_SSD.hex \

EEPROM_IMAGE += \
01_DIO_SSD.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 01_DIO_SSD.elf secondary-outputs

# Tool invocations
01_DIO_SSD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,01_DIO_SSD.map -mmcu=atmega32 -o "01_DIO_SSD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

01_DIO_SSD.lss: 01_DIO_SSD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 01_DIO_SSD.elf  >"01_DIO_SSD.lss"
	@echo 'Finished building: $@'
	@echo ' '

01_DIO_SSD.hex: 01_DIO_SSD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 01_DIO_SSD.elf  "01_DIO_SSD.hex"
	@echo 'Finished building: $@'
	@echo ' '

01_DIO_SSD.eep: 01_DIO_SSD.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 01_DIO_SSD.elf  "01_DIO_SSD.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 01_DIO_SSD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 01_DIO_SSD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 01_DIO_SSD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
