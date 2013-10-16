from PIL import Image, ImageFilter

image = Image.open('photo.bmp')
image = image.filter(ImageFilter.FIND_EDGES)
image.save('photo-edges.png')
