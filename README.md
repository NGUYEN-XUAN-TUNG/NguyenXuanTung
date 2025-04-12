Tên: Nguyễn Xuân Tùng
Mã SV: 24021666
## 1.Game: Fly-up
Đây là một game dựa trên ý tưởng chuyển động của Flappy Bird, nhưng có thay đổi về cách các chướng ngại vật hoạt động.  
Cách chơi game đơn giản: ấn nút space (hoặc click chuột) để nhảy nhằm không chạm vào các chướng ngại vật. 
## 2. Các tính năng và thuật toán được sử dụng:  
- Thư viện SDL2.
- Tách thành các file header khác nhau để dễ dàng quản lý các cấu trúc game và làm cho main gọn hơn.
- Các struct khác nhau được sử dụng để quản lí các đối tượng game khác nhau.
## 3. Các loại màn hình chính trong game:  
- Menu chính.
- Màn hình chọn nhân vật.  
- Màn hình chơi game. 
- Màn hình kết thúc ván chơi và hiện điểm số.
## 4. Các nguồn tham khảo:  
- Ý tưởng chính từ GitHub FlappyBird trong môn học, CodeLearn và TDev:  
  - [FlappyCopy trên GitHub](https://github.com/chauttm/flappyCopy/blob/main/level.cpp)  
  - [Hướng dẫn làm game Flappy Bird trên CodeLearn](https://codelearn.io/sharing/lam-game-flappy-bird-voi-pygame)  
  - [Học cách làm Game 2D](https://phattrienphanmem123az.com/lap-trinh-game-cpp)
- Hàm nhân vật di chuyển, màn hình di chuyển, âm thanh, hình ảnh, font chữ,...  
  - https://docs.google.com/document/d/1FZ3jTqHxtyZznNWiJmmve0zYu_aSliUqLP2OsMcdehQ/edit?tab=t.0#heading=h.g69r5ua9lzeh
  - Youtube: https://www.youtube.com/watch?v=QM4WW8hcsPU&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0
## 5. Đồ họa:  
- Ảnh nhân vật, hình nền, chướng ngại vật đều tự tạo với Canva:
  - [Hình ảnh trong game](https://www.canva.com/design/DAGj8mp5CaE/GtJrU1X42ly0zWY1YtO_jA/edit?utm_content=DAGj8mp5CaE&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
- Âm thanh và font chữ:
  - [Tiếng nhân vật bay lên](https://pixabay.com/sound-effects/bubble-pop-2-293341/)
  - [Tiếng kết thúc ván chơi](https://pixabay.com/sound-effects/fart-83471/)
  - [Press Start 2P](https://fonts.google.com/specimen/Press+Start+2P)
## 6. Checklist:  
- [x] Dùng các lệnh vẽ hình (SDL_RenderCopyEx)  
- [x] Texture  
- [x] Background  
- [x] Event bàn phím  
- [x] Event chuột  
- [x] Animation (hoạt hình) cho chướng ngại vật di chuyển  
- [x] Xử lý va chạm  
- [x] Score (có tính điểm) (lưu trong file highscore)  
- [x] Lưu bảng điểm  
- [x] Âm thanh
- [x] Font  
- [x] Menu
- [x] Pause/Resume  
- [x] Các điểm nổi bật khác:  
  - Chọn các nhân vật khác nhau  
  - Code viết dễ đọc (giáo viên đánh giá)  
  - Hiểu rõ code (giáo viên đánh giá)  



	