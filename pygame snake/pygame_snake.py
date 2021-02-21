import pygame
from random import randrange

RES = 800
SIZE = 50

x, y = randrange(0, RES, SIZE), randrange(0, RES, SIZE)
apple = randrange(0, RES, SIZE), randrange(0, RES, SIZE)
dirs = {'W': True,'S': True,'A': True,'D': True}
length = 1 # dlina
snake = [(x, y)] # змейка в виде списка координат
dx, dy = 0, 0 # направление движения
fps = 5 # скорость змейки
score = 0
pygame.init()
sc = pygame.display.set_mode([RES, RES])
clock = pygame.time.Clock()
font_score = pygame.font.SysFont('Arial', 26, bold = True)
font_end = pygame.font.SysFont('Arial', 66, bold = True)
img = pygame.image.load('Baby.tux-800x800.png').convert()

while True:
    sc.blit(img, (0, 0))
    #sc.fill(pygame.Color('black'))
    # drawing snake
    [(pygame.draw.rect(sc, pygame.Color('green'), (i , j, SIZE-2, SIZE-2))) for i, j in snake] # -2 для отображения контура змейки
    pygame.draw.rect(sc, pygame.Color('red'), (*apple, SIZE, SIZE))
    #show score
    render_score = font_score.render(f'SCORE: {score}', 1, pygame.Color('orange'))
    sc.blit(render_score, (5, 5))
    # moving snake
    x += dx * SIZE
    y += dy * SIZE
    snake.append((x, y))
    snake = snake[-length:]
    # eating apple
    if snake[-1] == apple:
        apple = randrange(0, RES, SIZE), randrange(0, RES, SIZE)
        length += 1
        fps += 1
        score += 1
    # game over
    if x < 0 or x > RES - SIZE or y < 0 or y > RES - SIZE or len(snake) != len(set(snake)):
        while True:
            render_end = font_end.render('GAME OVER', 1, pygame.Color('orange'))
            sc.blit(render_end, (RES // 2 - 150, RES // 2.5)) # убейте меня за эти подсчеты боже
            pygame.display.flip()
            for event in pygame.event.get():
                if event.type == pygame.quit:
                    exit()
        

    pygame.display.flip()
    clock.tick(fps)

    for event in pygame.event.get():
        if event.type == pygame.quit:
            exit()
        
    # key press
    key = pygame.key.get_pressed()
    if key [pygame.K_w] and dirs['W']:
        dx, dy = 0, -1
        dirs = {'W': True,'S': False,'A': True,'D': True}
    if key [pygame.K_s] and dirs['S']:
        dx, dy = 0, 1
        dirs = {'W': False,'S': True,'A': True,'D': True}
    if key [pygame.K_a] and dirs['A']:
        dx, dy = -1, 0
        dirs = {'W': True,'S': True,'A': True,'D': False}
    if key [pygame.K_d] and dirs['D']:
        dx, dy = 1, 0
        dirs = {'W': True,'S': True,'A': False,'D': True}

