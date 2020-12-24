import pygame.font
class Light():
    def __init__(self, ai_settings, screen, color, positionX, positionY):
        """Initialize button attributes."""
        self.screen = screen
        self.screen_rect = screen.get_rect()
        # Set the dimensions and properties of the button.
        self.width, self.height = 200, 50
        self.button_color = color
        self.text_color = (255, 255, 255)
        #self.font = pygame.font.SysFont(None, 48)
        self.rect = pygame.Rect(0, 0, self.width, self.height)
        self.rect.centerx = positionX
        self.rect.centery = positionY

    def draw_light(self):
        # Draw blank button and then draw message.
        self.screen.fill(self.button_color, self.rect)
        self.screen.blit(self.msg_image, self.msg_image_rect)