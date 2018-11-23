/*
 * Macros
 */

/* Pin definitions */
#define E_PORT   PORTB
#define E_DDR    DDRB
#define E        0
#define LCD_PORT PORTC
#define LCD_DDR  DDRC
#define DB4      0
#define DB5      1
#define DB6      2
#define DB7      3
#define RW       4
#define RS       5

/* Commands */
#define lcd_cmd(x)     lcd_send(x, 0)
#define lcd_char(x)    lcd_send(x, 1)

/* Bit switch shortcuts */
#define lcd_rs_on()    LCD_PORT |= (1 << RS)
#define lcd_rs_off()   LCD_PORT &= ~(1 <<RS)
#define lcd_rw_on()    LCD_PORT |= (1 << RW)
#define lcd_rw_off()   LCD_PORT &= ~(1 << RW)
#define lcd_e_on()     E_PORT |= (1 << E)
#define lcd_e_off()    E_PORT &= ~(1 << E)
#define lcd_e_delay()  _delay_us(E_PULSE_TIME)

/* Magic numbers */
#define E_PULSE_TIME 250
#define LCD_LINE_1    0x80
#define LCD_LINE_2    0xC0

/*
 * Function prototypes
 */

void lcd_epulse(void);

void lcd_send(int data, int rs);

void lcd_putc(char c);

void lcd_init(void);
