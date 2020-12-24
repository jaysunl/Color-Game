import pygame
from settings import Settings
from button import Button
import time
import random
pygame.init()
ai_settings = Settings()
screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height))
pygame.display.set_caption("Color Game")
white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
dark_red = (155, 0, 0)
dark_green = (0, 155, 0)
dark_blue = (0, 0, 155)
button_red = Button(ai_settings, screen, "red", red, 200, 600, white)
button_green = Button(ai_settings, screen, "green", green, 400, 600, white)
button_blue = Button(ai_settings, screen, "blue", blue, 600, 600, white)
start_button = Button(ai_settings, screen, "Start", white, 600, 100, black)
stop_button = Button(ai_settings, screen, "Stop", white, 200, 100, black)
instruct_button = Button(ai_settings, screen, "How to play", white, 700, 750, black)
starttime = time.time()
game_started = False
red_pressed = False
green_pressed = False
blue_pressed = False
score = 0
target_color = [100, 100, 100]
just_enter = True

def display_box(screen, message, positionX, positionY):
  "Print a message in a box in the middle of the screen"
  fontobject = pygame.font.Font(None,38)
  if len(message) != 0:
    screen.blit(fontobject.render(message, 1, white),
                ((screen.get_width() / 2 - positionX), (screen.get_height() / 2) - positionY))

def show_instruct():
    go_back = False
    while True:
        screen.fill(ai_settings.bg_color)
        display_box(screen, "Press d to control red button", 200, 100)
        display_box(screen, "Press f to control green button", 200, 50)
        display_box(screen, "Press j to control blue button", 200, 0)
        display_box(screen, "Press k to reset lamp color", 200, -50)
        display_box(screen, "Press return to go back", 200, -100)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    go_back = True
        if go_back:
            break
        pygame.display.flip()

while True:
    screen.fill(ai_settings.bg_color)
    mouse_x, mouse_y = pygame.mouse.get_pos()
    start_button.draw_button()
    stop_button.draw_button()
    time_left = (int)((60 - (time.time() - starttime)) * 10) / 10.0
    if just_enter:
        display_box(screen, "timer", 20, -50)
    elif (game_started and time_left <= 0):
        display_box(screen, "game over", 30, -50)
        game_started = False
    elif (game_started):
        display_box(screen, (str)(time_left), 20, -50)
    else:
        display_box(screen, "game over", 30, -50)
    display_box(screen, (str)(score), 20, -300)
    Target_color = (target_color[0], target_color[1], target_color[2])
    pygame.draw.circle(screen, Target_color, [600, 300], 100, 0)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            if start_button.rect.collidepoint(mouse_x, mouse_y):
                game_started = True
                target_color = [100 + random.randint(0,1) * 155, 100 + random.randint(0,1) * 155, 100 + random.randint(0,1) * 155]
                if (target_color[0] == 100 and target_color[1] == 100 and target_color[2] == 100):
                    target_color = [255, 255, 255]
                starttime = time.time()
                just_enter = False
                score = 0
            elif instruct_button.rect.collidepoint(mouse_x, mouse_y):
                show_instruct()
            elif stop_button.rect.collidepoint(mouse_x, mouse_y):
                game_started = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_d:
                red_pressed = True
            if event.key == pygame.K_f:
                green_pressed = True
            if event.key == pygame.K_j:
                blue_pressed = True
            if event.key == pygame.K_k:
                red_pressed = False
                blue_pressed = False
                green_pressed = False
    if red_pressed:
        button_red.button_color = dark_red
    else:
        button_red.button_color = red
    if green_pressed:
        button_green.button_color = dark_green
    else:
        button_green.button_color = green
    if blue_pressed:
        button_blue.button_color = dark_blue
    else:
        button_blue.button_color = blue
    button_red.draw_button()
    button_green.draw_button()
    button_blue.draw_button()
    instruct_button.draw_button()
    your_color = [100, 100, 100]
    if red_pressed:
        your_color[0] = your_color[0] + 155
    if green_pressed:
        your_color[1] = your_color[1] + 155
    if blue_pressed:
        your_color[2] = your_color[2] + 155
    Your_color = (your_color[0], your_color[1], your_color[2])
    pygame.draw.circle(screen, your_color, [200, 300], 100, 0)
    if game_started and your_color[0] == target_color[0] and your_color[1] == target_color[1] and your_color[2] == target_color[2]:
        score += 1
        target_color = [100 + random.randint(0,1) * 155, 100 + random.randint(0,1) * 155, 100 + random.randint(0,1) * 155]
        if (target_color[0] == 100 and target_color[1] == 100 and target_color[2] == 100):
            target_color = [255, 255, 255]
        your_color = [100, 100, 100]
        red_pressed = False
        blue_pressed = False
        green_pressed = False
    pygame.display.flip()