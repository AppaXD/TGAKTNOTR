#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>
#include <string>

int main()
{
    // initialize random
    std::random_device rd;
    std::mt19937 rng(rd());

    // get and create screen width and height
    sf::VideoMode vmode = sf::VideoMode::getDesktopMode();
    int width = vmode.width/2;
    int height = vmode.height/2;
    float w8 = width/8;

    // background count
    int bgcount = 1000;

    // load background texture
    sf::Texture t_background;
    t_background.loadFromFile("Images/bg3.png");
    t_background.setSmooth(true);
    t_background.setRepeated(true);

    // load textures
    sf::Texture t_knightIdle;
    t_knightIdle.loadFromFile("Images/idle.png");

    sf::Texture t_run1;
    t_run1.loadFromFile("Images/walk_01.png");

    sf::Texture t_run2;
    t_run2.loadFromFile("Images/walk_02.png");

    sf::Texture t_run3;
    t_run3.loadFromFile("Images/walk_03.png");

    sf::Texture t_run4;
    t_run4.loadFromFile("Images/walk_04.png");

    sf::Texture t_run5;
    t_run5.loadFromFile("Images/walk_05.png");

    sf::Texture t_run6;
    t_run6.loadFromFile("Images/walk_06.png");

    sf::Texture t_attack1;
    t_attack1.loadFromFile("Images/attack_01.png");

    sf::Texture t_attack2;
    t_attack2.loadFromFile("Images/attack_02.png");

    sf::Texture t_attack3;
    t_attack3.loadFromFile("Images/attack_03.png");

    sf::Texture t_attack4;
    t_attack4.loadFromFile("Images/attack_04.png");

    sf::Texture t_attack5;
    t_attack5.loadFromFile("Images/attack_05.png");

    sf::Texture t_attack6;
    t_attack6.loadFromFile("Images/attack_06.png");

    sf::Texture t_jump1;
    t_jump1.loadFromFile("Images/jump_01.png");

    sf::Texture t_jump2;
    t_jump2.loadFromFile("Images/jump_02.png");

    // ninja textures

    sf::Texture t_nAttack1;
    t_nAttack1.loadFromFile("Images/Ninja/attack_01.png");

    sf::Texture t_nAttack2;
    t_nAttack2.loadFromFile("Images/Ninja/attack_02.png");

    sf::Texture t_nAttack3;
    t_nAttack3.loadFromFile("Images/Ninja/attack_03.png");

    sf::Texture t_nAttack4;
    t_nAttack4.loadFromFile("Images/Ninja/attack_04.png");

    sf::Texture t_nAttack5;
    t_nAttack5.loadFromFile("Images/Ninja/attack_05.png");

    sf::Texture t_nAttack6;
    t_nAttack6.loadFromFile("Images/Ninja/attack_06.png");

    sf::Texture t_shootFb1;
    t_shootFb1.loadFromFile("Images/Ninja/shoot_1.png");

    sf::Texture t_shootFb2;
    t_shootFb2.loadFromFile("Images/Ninja/shoot_2.png");

    sf::Texture t_shootFb3;
    t_shootFb3.loadFromFile("Images/Ninja/shoot_3.png");

    sf::Texture t_shootFb4;
    t_shootFb4.loadFromFile("Images/Ninja/shoot_4.png");

    sf::Texture t_shootFb5;
    t_shootFb5.loadFromFile("Images/Ninja/shoot_5.png");

    sf::Texture t_shootFb6;
    t_shootFb6.loadFromFile("Images/Ninja/shoot_6.png");


    sf::Texture t_ninjaIdle;
    t_ninjaIdle.loadFromFile("Images/Ninja/idle.png");

    // smoke textures
    sf::Texture t_smoke1;
    t_smoke1.loadFromFile("Images/Smoke/smoke_01.png");

    sf::Texture t_smoke2;
    t_smoke2.loadFromFile("Images/Smoke/smoke_02.png");

    sf::Texture t_smoke3;
    t_smoke3.loadFromFile("Images/Smoke/smoke_03.png");

    sf::Texture t_smoke4;
    t_smoke4.loadFromFile("Images/Smoke/smoke_04.png");

    sf::Texture t_smoke5;
    t_smoke5.loadFromFile("Images/Smoke/smoke_05.png");

    sf::Texture t_smoke6;
    t_smoke6.loadFromFile("Images/Smoke/smoke_06.png");

    sf::Texture t_smoke7;
    t_smoke7.loadFromFile("Images/Smoke/smoke_07.png");

    sf::Texture t_smoke8;
    t_smoke8.loadFromFile("Images/Smoke/smoke_08.png");

    sf::Texture t_smoke9;
    t_smoke9.loadFromFile("Images/Smoke/smoke_09.png");

    sf::Texture t_smoke10;
    t_smoke10.loadFromFile("Images/Smoke/smoke_10.png");

    // fireball textures

    sf::Texture t_fb1;
    t_fb1.loadFromFile("Images/Fireball/fb_01.png");

    sf::Texture t_fb2;
    t_fb2.loadFromFile("Images/Fireball/fb_02.png");

    sf::Texture t_fb3;
    t_fb3.loadFromFile("Images/Fireball/fb_03.png");

    sf::Texture t_fb4;
    t_fb4.loadFromFile("Images/Fireball/fb_04.png");

    sf::Sprite ninja;
    ninja.setTexture(t_ninjaIdle);
    ninja.move(512+width/2, height/2.5);
    ninja.setScale(-0.4, 0.4);

    int enemiesKilled = 0;

    // create knight
    sf::Sprite knight;
    knight.setTexture(t_knightIdle);
    knight.move(-w8, height/3.625);

    int hitboxWidth = width/10;
    sf::RectangleShape hitbox(sf::Vector2f(hitboxWidth, 200));
    hitbox.setPosition(width/5.5, height/3);
    hitbox.setFillColor(sf::Color::White);

    sf::Sprite fireball;
    fireball.setTexture(t_fb1);
    fireball.setScale(-1, 1);

    sf::RectangleShape ninjaHitbox = hitbox;
    ninjaHitbox.setPosition(width/1.3, height/2.2);

    double originalSize = width/5;
    double originalHeight = height/24;

    sf::RectangleShape sword(sf::Vector2f(22.5, 110));
    sword.setFillColor(sf::Color::White);

    sf::RectangleShape ninjaSword = sword;

    sf::RectangleShape healthBoxHero(sf::Vector2f(originalSize, originalHeight));
    healthBoxHero.setOutlineColor(sf::Color::White);
    healthBoxHero.setOutlineThickness(8);
    healthBoxHero.setPosition(width/15, height/15);
    sf::RectangleShape healthBoxHeroFill(sf::Vector2f(originalSize, originalHeight));
    healthBoxHeroFill.setFillColor(sf::Color::Red);
    healthBoxHeroFill.setPosition(width/15, height/15);

    sf::RectangleShape healthBoxNinja(sf::Vector2f(originalSize, originalHeight));
    healthBoxNinja.setOutlineColor(sf::Color::White);
    healthBoxNinja.setOutlineThickness(8);
    healthBoxNinja.setPosition(width-width/15-healthBoxNinja.getSize().x, height/15);
    sf::RectangleShape healthBoxNinjaFill(sf::Vector2f(originalSize, originalHeight));
    healthBoxNinjaFill.setFillColor(sf::Color::Blue);
    healthBoxNinjaFill.setPosition(width-width/15-healthBoxNinja.getSize().x, height/15);

    sf::RectangleShape slideBoundary(sf::Vector2f(25, 150));
    slideBoundary.setFillColor(sf::Color::White);
    slideBoundary.setPosition(width/12, height/2.25);

    float bt = 1.37*1.05;

    sf::Sprite bg;
    bg.setTexture(t_background);
    sf::FloatRect bgsize = bg.getGlobalBounds();
    bg.setScale(width/bgsize.width*1.05, height/bgsize.height);

    std::vector<sf::Sprite> backgrounds;
    std::vector<sf::Sprite> fireballs;
    std::vector<sf::CircleShape> fireballCircles;
    std::vector<int> fireballAnimationStages;
    std::vector<float> fireballTimers;
    float fbAnimationDelay = 0.1;

    for(int i = -1; i < bgcount; ++i)
    {
        bg.setPosition(bgsize.width*i*bt, 0);
        backgrounds.push_back(bg);
    }

    // values
    double health = 100.0;
    double ninjaHealth = 50.0;
    double ninjaHealthMax = 50.0;
    double minDamage = 15.0; // 0.99*
    double maxDamage = 25.0;
    double ninjaDamageMin = 10.0; // 1.05* mb change
    double ninjaDamageMax = 15.0;

    // boolean for running
    bool running = false;

    // camera slide after kill
    bool sliding = false;

    // boolean for jumping
    bool jumping = false;

    // keep track of heroAnimation
    int heroAnimationStage = 0;
    int enemyAnimationStage = 0;
    int jumpAnimationStage = 0;

    // run speed
    int runSpeed = 500;

    // free run = you actually move along the screen, only available during fights
    bool freerun = true;

    // time inbetween animations
    double animationDelay = 0.075;
    double jumpAnimationDelay = 0.025;

    // keep track of running direction
    int direction = 1; // 1 = right, -1 = left
    sf::Vector2f run(0, 0);

    // load font
    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text gameOverText;
    sf::Text enemiesKilledText;
    gameOverText.setFont(font);
    enemiesKilledText.setFont(font);
    gameOverText.setString("GAME OVER");
    enemiesKilledText.setString("enemies Killed: 0");
    gameOverText.setCharacterSize(120);
    gameOverText.setOrigin(gameOverText.getGlobalBounds().width/2.0f, gameOverText.getGlobalBounds().height/2.0f);
    gameOverText.setPosition(width/2, height/2.5);
    gameOverText.setFillColor(sf::Color(196, 173, 60));
    enemiesKilledText.setCharacterSize(35);
    enemiesKilledText.setOrigin(enemiesKilledText.getGlobalBounds().width/2.0f, enemiesKilledText.getGlobalBounds().height/2.0f);
    enemiesKilledText.setPosition(width/2, height/12);
    sf::Text spaceToBegin;
    spaceToBegin.setFont(font);
    spaceToBegin.setString("Press SPACE to start");
    spaceToBegin.setFillColor(sf::Color(196, 173, 60));
    spaceToBegin.setCharacterSize(50);
    spaceToBegin.setOrigin(spaceToBegin.getGlobalBounds().width/2.0f, spaceToBegin.getGlobalBounds().height/2.0f);
    spaceToBegin.setPosition(width/2, height/3.5);

    // background music
    sf::Music music;
    music.openFromFile("music.ogg");
    music.setVolume(75);
    music.setLoop(true);
    music.play();

    sf::SoundBuffer fbSoundBuffer;
    fbSoundBuffer.loadFromFile("fireball.ogg");
    sf::Sound fbSound;
    fbSound.setBuffer(fbSoundBuffer);

    sf::SoundBuffer swordHitBuffer;
    swordHitBuffer.loadFromFile("hit.ogg");
    sf::Sound swordHit;
    swordHit.setBuffer(swordHitBuffer);

    sf::SoundBuffer swordSwingBuffer;
    swordSwingBuffer.loadFromFile("swing.ogg");
    sf::Sound swordSwing;
    swordSwing.setBuffer(swordSwingBuffer);

    // booleans
    bool stationary = false;
    bool hitting = false;
    bool heroAnimation = false;
    bool enemyAnimation = false;
    bool hasHit = false;
    bool smokePlume = false;
    bool ninjaHitting = false;
    bool ninjaHasHit = false;
    bool ninjaShooting = false;
    bool smokePlumeHero = false;
    bool gameOver = false;
    bool gameStart = false;

    // create timer
    sf::Clock clock;
    float DeltaTime = 0.0;
    float heroAnimationTimer = 0.0;
    float enemyAnimationTimer = 0.0;
    float jumpAnimationTimer = 0.0;
    float enemyAttackTimer = 0.0;
    float enemyAttackDelay = 1.25;

    bool pause = false;

    // create window
    sf::RenderWindow window(sf::VideoMode(width, height), "Game");

    // loop until window closes
    while(window.isOpen())
    {
        DeltaTime = clock.restart().asSeconds();
        float movement = run.x*runSpeed*DeltaTime;
        if(heroAnimation && !pause && !gameStart)
        {
            heroAnimationTimer += DeltaTime;
        }

        if(enemyAnimation && !pause && !gameStart)
        {
            enemyAnimationTimer += DeltaTime;
        }

        if(jumping && !pause && !gameStart)
        {
            jumpAnimationTimer += DeltaTime;
        }

        if(!gameStart)
            enemyAttackTimer += DeltaTime;

        sf::Event event;
        while(window.pollEvent(event))
        {
            int type = event.type;
            if(type == sf::Event::Closed)
            {
                window.close();
                exit(0);
            }
            else if(type == sf::Event::KeyPressed && !stationary && !gameOver/* && !gameStart*/)
            {
                int key = event.key.code;

                if(key == sf::Keyboard::D)
                {
                    if(!heroAnimation)
                    {
                        heroAnimation = true;
                        heroAnimationStage = 0;
                        running = true;
                        if(direction != 1)
                        {
                            direction = 1;
                            knight.move(-512, 0);
                            knight.setScale(1,1);
                        }
                        run.x = 1;
                    }
                }

                if(key == sf::Keyboard::A)
                {
                    if(!heroAnimation && freerun && !stationary && !gameOver && !gameStart)
                    {
                        running = true;
                        heroAnimation = true;
                        heroAnimationStage = 0;
                        if(direction != -1)
                        {
                            direction = -1;
                            knight.move(512, 0);
                            knight.setScale(-1,1);
                        }
                        run.x = -1;
                    }
                }

                if(key == sf::Keyboard::W)
                {
                    if(!jumping && !gameOver && !gameStart)
                    {
                        running = false;
                        jumping = true;
                    }
                }

                if(key == sf::Keyboard::Space)
                {
                    if(gameStart)
                        gameStart = false;
                    else
                        gameStart = true;
                }
            }
            else if(type == sf::Event::KeyReleased)
            {
                int key = event.key.code;

                if(key == sf::Keyboard::D || key == sf::Keyboard::A)
                {
                    if(heroAnimation == true) heroAnimation = false;
                    running = false;
                    knight.setTexture(t_knightIdle);
                    run.x = 0;
                    heroAnimationTimer = 0.0;
                }
            }
            else if(type == sf::Event::MouseButtonPressed)
            {
                int mouse = event.mouseButton.button;

                if(mouse == sf::Mouse::Left && !sliding)
                {
                    if(!heroAnimation || running)
                    {
                        running = false;
                        heroAnimation = true;
                        stationary = true;
                        hitting = true;
                        heroAnimationStage = 0;
                    }
                }
            }
        }

        if(!gameOver && !gameStart)
        {
            if(heroAnimationTimer > animationDelay)
            {
                heroAnimationTimer = 0.0;
                heroAnimationStage+=1;

                if(running)
                {
                    switch(heroAnimationStage)
                    {
                        case 1 : knight.setTexture(t_run1);
                                 break;
                        case 2 : knight.setTexture(t_run2);
                                 break;
                        case 3 : knight.setTexture(t_run3);
                                 break;
                        case 4 : knight.setTexture(t_run4);
                                 break;
                        case 5 : knight.setTexture(t_run5);
                                 break;
                        case 6 : knight.setTexture(t_run6);
                                 heroAnimationStage = 0;
                                 break;

                    }
                }
                else if(hitting)
                {
                    run.x = 0;

                    sf::Vector2f position = knight.getPosition();

                    if(direction == -1)
                    {
                        switch(heroAnimationStage)
                        {
                            case 1 : knight.setTexture(t_attack1);
                                     hasHit = false;
                                     sword.setRotation(100);
                                     sword.setPosition(position.x-140, height/1.65);
                                     break;
                            case 2 : knight.setTexture(t_attack2);
                                     sword.setRotation(93);
                                     sword.move(-2, -15);
                                     break;
                            case 3 : knight.setTexture(t_attack3);
                                     sword.setRotation(95);
                                     sword.move(-148, 12);
                                     break;
                            case 4 : knight.setTexture(t_attack4);
                                     sword.setRotation(92);
                                     sword.move(-10, 5);
                                     break;
                            case 5 : knight.setTexture(t_attack5);
                                     sword.setRotation(90);
                                     sword.move(-5, 2);
                                     break;
                            case 6 : knight.setTexture(t_attack6);
                                     break;
                            case 7 : knight.setTexture(t_knightIdle);
                                     sword.setPosition(0, 0);
                                     heroAnimationStage = 0;
                                     heroAnimation = false;
                                     hitting = false;
                                     stationary = false;
                                     break;
                        }
                    }
                    else
                    {
                        switch(heroAnimationStage)
                        {
                            case 1 : knight.setTexture(t_attack1);
                                     swordSwing.play();
                                     hasHit = false;
                                     sword.setRotation(80);
                                     sword.setPosition(position.x+265, height/1.75);
                                     break;
                            case 2 : knight.setTexture(t_attack2);
                                     sword.setRotation(87);
                                     sword.move(5, 0);
                                     break;
                            case 3 : knight.setTexture(t_attack3);
                                     sword.setRotation(85);
                                     sword.move(148, 12);
                                     break;
                            case 4 : knight.setTexture(t_attack4);
                                     sword.setRotation(88);
                                     sword.move(6, 5);
                                     break;
                            case 5 : knight.setTexture(t_attack5);
                                     sword.setRotation(90);
                                     sword.move(6, 8);
                                     break;
                            case 6 : knight.setTexture(t_attack6);
                                     break;
                            case 7 : knight.setTexture(t_knightIdle);
                                     sword.setPosition(0, 0);
                                     heroAnimationStage = 0;
                                     heroAnimation = false;
                                     hitting = false;
                                     stationary = false;
                                     break;
                        }
                    }
                }

                if(smokePlumeHero)
                {
                    switch(heroAnimationStage)
                    {
                        case 1 : stationary = true;
                                 hitting = false;
                                 knight.setTexture(t_smoke10);
                                 //knight.move(width/10, 0);
                                 break;
                        case 2 : knight.setTexture(t_smoke2);
                                 break;
                        case 3 : knight.setTexture(t_smoke3);
                                 break;
                        case 4 : knight.setTexture(t_smoke4);
                                 break;
                        case 5 : knight.setTexture(t_smoke5);
                                 break;
                        case 6 : knight.setTexture(t_smoke6);
                                 break;
                        case 7 : knight.setTexture(t_smoke7);
                                 break;
                        case 8 : knight.setTexture(t_smoke8);
                                 break;
                        case 9 : knight.setTexture(t_smoke9);
                                 break;
                        case 10 : knight.setTexture(t_smoke10);
                                  break;
                        case 11 : knight.move(-width*2, 0);
                                  enemiesKilledText.setFillColor(sf::Color(196, 173, 60));
                                  enemiesKilledText.setPosition(width/2, height/1.75);
                                  gameOver = true;
                                  break;
                    }
                }
            }

            if(jumpAnimationTimer > jumpAnimationDelay)
            {
                jumpAnimationTimer = 0.0;
                ++jumpAnimationStage;

                switch(jumpAnimationStage)
                {
                    case 1 : knight.setTexture(t_jump1);
                             knight.move(0, -height/40); // width/150 for moving forwards
                             hitbox.move(0, -height/40);
                             break;
                    case 2 : knight.move(0, -height/50);
                             hitbox.move(0, -height/50);
                             break;
                    case 3 : knight.setTexture(t_jump2);
                             knight.move(0, -height/60);
                             hitbox.move(0, -height/60);
                             break;
                    case 4 : knight.move(0, -height/60);
                             hitbox.move(0, -height/60);
                             break;
                    case 5 : knight.move(0, -height/70);
                             hitbox.move(0, -height/70);
                             break;
                    case 6 : knight.move(0, -height/70);
                             hitbox.move(0, -height/70);
                             break;
                    case 7 : knight.move(0, -height/70);
                             hitbox.move(0, -height/70);
                             break;
                    case 8 : knight.move(0, -height/70);
                             hitbox.move(0, -height/70);
                             break;
                    case 9 : knight.move(0, -height/75);
                             hitbox.move(0, -height/75);
                             break;
                    case 10 : knight.move(0, -height/75);
                              hitbox.move(0, -height/75);
                              break;
                    case 11 : knight.move(0, -height/80);
                              hitbox.move(0, -height/80);
                              break;
                    case 12 : knight.move(0, -height/80);
                              hitbox.move(0, -height/80);
                              break;
                    case 13 : knight.move(0, -height/90);
                              hitbox.move(0, -height/90);
                              break;
                    case 14 : knight.move(0, -height/90);
                              hitbox.move(0, -height/90);
                              break;
                    case 15 : knight.move(0, -height/95);
                              hitbox.move(0, -height/95);
                              break;
                    case 16 : knight.move(0, -height/95);
                              hitbox.move(0, -height/95);
                              break;
                    case 17 : knight.move(0, height/40);
                              hitbox.move(0, height/40);
                              break;
                    case 18 : knight.move(0, height/50);
                              hitbox.move(0, height/50);
                              break;
                    case 19 : knight.move(0, height/60);
                              hitbox.move(0, height/60);
                              break;
                    case 20 : knight.move(0, height/60);
                              hitbox.move(0, height/60);
                              break;
                    case 21 : knight.move(0, height/70);
                              hitbox.move(0, height/70);
                              break;
                    case 22 : knight.move(0, height/70);
                              hitbox.move(0, height/70);
                              break;
                    case 23 : knight.move(0, height/70);
                              hitbox.move(0, height/70);
                              break;
                    case 24 : knight.move(0, height/70);
                              hitbox.move(0, height/70);
                              break;
                    case 25 : knight.move(0, height/75);
                              hitbox.move(0, height/75);
                              break;
                    case 26 : knight.move(0, height/75);
                              hitbox.move(0, height/75);
                              break;
                    case 27 : knight.move(0, height/80);
                              hitbox.move(0, height/80);
                              break;
                    case 28 : knight.move(0, height/80);
                              hitbox.move(0, height/80);
                              break;
                    case 29 : knight.move(0, height/90);
                              hitbox.move(0, height/90);
                              break;
                    case 30 : knight.setTexture(t_jump1);
                              knight.move(0, height/90);
                              hitbox.move(0, height/90);
                              break;
                    case 31 : knight.move(0, height/95);
                              hitbox.move(0, height/95);
                              break;
                    case 32 : knight.move(0, height/95);
                              hitbox.move(0, height/95);
                              break;
                    case 33 : knight.setTexture(t_knightIdle);
                              jumpAnimationStage = 0;
                              jumping = false;
                              break;
                }
            }

            if(enemyAnimationTimer > animationDelay)
            {
                enemyAnimationTimer = 0.0;
                ++enemyAnimationStage;
                if(smokePlume)
                {
                    switch(enemyAnimationStage)
                    {
                        case 1 : stationary = true;
                                 ninjaHitting = false;
                                 ninjaShooting = false;
                                 ninja.setTexture(t_smoke10);
                                 ninja.move(-width/10, 0);
                                 break;
                        case 2 : ninja.setTexture(t_smoke2);
                                 break;
                        case 3 : ninja.setTexture(t_smoke3);
                                 break;
                        case 4 : heroAnimationStage = 0;
                                 heroAnimation = false;
                                 ninja.setTexture(t_smoke4);
                                 break;
                        case 5 : ninja.setTexture(t_smoke5);
                                 break;
                        case 6 : ninja.setTexture(t_smoke6);
                                 break;
                        case 7 : ninja.setTexture(t_smoke7);
                                 break;
                        case 8 : ninja.setTexture(t_smoke8);
                                 break;
                        case 9 : ninja.setTexture(t_smoke9);
                                 break;
                        case 10 : ninja.setTexture(t_smoke10);
                                 break;
                        case 11 : ninja.setTexture(t_ninjaIdle);
                                  ninja.move(256+width, 0);
                                  ninjaHealth = ninjaHealthMax;
                                  minDamage*=0.98;
                                  maxDamage*=0.98;
                                  ninjaDamageMax*=1.02;
                                  ninjaDamageMin*=1.02;
                                  healthBoxNinjaFill.setSize(sf::Vector2f(originalSize, originalHeight));
                                  ninjaHitbox.setPosition(ninja.getPosition().x-256, height/3);
                                  //knight.setPosition(-128, knight.getPosition().y);
                                  //hitbox.setPosition(width/6, hitbox.getPosition().y);
                                  freerun = false;
                                  stationary = true;
                                  smokePlume = false;
                                  sliding = true;
                                  enemyAnimation = false;
                                  enemyAnimationStage = 0;
                                  break;
                    }
                }

                if(ninjaHitting)
                {
                    sf::Vector2f position = ninja.getPosition();

                    switch(enemyAnimationStage)
                    {
                        case 1 : ninja.setTexture(t_nAttack1);
                                 ninjaSword.setPosition(position.x-150, height/1.53);
                                 ninjaSword.setRotation(120);
                                 break;
                        case 2 : ninja.setTexture(t_nAttack2);
                                 ninjaSword.move(-100, -50);
                                 ninjaSword.setRotation(80);
                                 break;
                        case 3 : ninja.setTexture(t_nAttack3);
                                 ninjaSword.move(-5, -20);
                                 ninjaSword.setRotation(100);
                                 break;
                        case 4 : ninja.setTexture(t_nAttack4);
                                 ninjaSword.move(-10, -10);
                                 ninjaSword.setRotation(105);
                                 break;
                        case 5 : ninja.setTexture(t_nAttack5);
                                 break;
                        case 6 : ninja.setTexture(t_nAttack6);
                                 break;
                        case 7 : ninja.setTexture(t_ninjaIdle);
                                 ninjaSword.setPosition(0, 0);
                                 enemyAnimationStage = 0;
                                 enemyAnimation = false;
                                 ninjaHitting = false;
                    }
                }

                if(ninjaShooting)
                {
                    switch(enemyAnimationStage)
                    {
                        case 1 : ninja.setTexture(t_shootFb1);
                                 break;
                        case 2 : ninja.setTexture(t_shootFb2);
                                 fbSound.play();
                                 break;
                        case 3 : ninja.setTexture(t_shootFb3);
                                 break;
                        case 4 : ninja.setTexture(t_shootFb4);
                                 break;
                        case 5 : ninja.setTexture(t_shootFb5);
                                 break;
                        case 6 : ninja.setTexture(t_shootFb6);
                            {
                                 sf::Sprite nfb = fireball;
                                 nfb.setPosition(ninja.getPosition().x-250, height/1.9);
                                 fireballs.push_back(nfb);
                                 sf::CircleShape circle(25.0f);
                                 circle.setFillColor(sf::Color::White);
                                 circle.setPosition(nfb.getPosition().x-105, height/1.9);
                                 fireballCircles.push_back(circle);
                                 fireballAnimationStages.push_back(0);
                                 fireballTimers.push_back(0.0f);
                                 break;
                            }
                        case 7 : ninja.setTexture(t_ninjaIdle);
                                 ninjaShooting = false;
                                 enemyAnimationStage = 0;
                                 enemyAnimation = false;
                                 break;

                    }
                }
            }

            if(enemyAttackTimer > enemyAttackDelay)
            {
                enemyAttackTimer = 0.0;

                sf::Vector2f knightPosition = knight.getPosition();
                sf::Vector2f position = ninja.getPosition();

                if(knightPosition.x + (position.x-256) > width)
                {
                    enemyAnimation = true;
                    enemyAnimationStage = 0;
                    ninjaHitting = true;
                    ninjaHasHit = false;
                }
                else
                {
                    enemyAnimation = true;
                    enemyAnimationStage = 0;
                    ninjaShooting = true;
                }
            }

            if(!stationary && freerun && !sliding)
            {
                knight.move(movement, 0);

                float kpx = knight.getPosition().x;

                if(direction != -1) hitbox.setPosition(kpx+(width/4.363), jumping ? knight.getPosition().y : height/3);
                else hitbox.setPosition(kpx-(width/3.2), jumping ? knight.getPosition().y : height/3);

                if(hitbox.getPosition().x < 0)
                {
                    knight.move(1, 0);
                    hitbox.move(1, 0);
                }
            }

            if(!freerun && movement >= 0)
            {
                 ninja.move(-movement, 0);
                 ninjaHitbox.move(-movement, 0);
            }

            if(ninja.getPosition().x < width)
            {
                freerun = true;
            }
            else
            {
                freerun = false;
            }

            if(hitbox.getGlobalBounds().intersects(ninjaHitbox.getGlobalBounds()))
            {
                knight.move(-1, 0);
                hitbox.move(-1, 0);
            }

            if(ninjaSword.getGlobalBounds().intersects(hitbox.getGlobalBounds()) && !ninjaHasHit)
            {
                ninjaHasHit = true;
                std::uniform_int_distribution<int> uni(ninjaDamageMin, ninjaDamageMax);
                double damageDealt = uni(rng);
                health -= damageDealt;
                swordHit.play();
                std::cout << "The Ninja has dealt " << damageDealt << " damage.\n";
                if(health < 0)
                {
                    heroAnimationStage = 0;
                    heroAnimation = true;
                    smokePlumeHero = true;
                    health = 0;
                }
                healthBoxHeroFill.setSize(sf::Vector2f(health/100*originalSize, originalHeight));
            }

            if(sword.getGlobalBounds().intersects(ninjaHitbox.getGlobalBounds()) && !hasHit)
            {
                if(ninjaHealth > 0)
                {
                    hasHit = true;
                    std::uniform_int_distribution<int> uni(minDamage, maxDamage);
                    double damageDealt = uni(rng);
                    ninjaHealth -= damageDealt;
                    swordHit.play();
                    std::cout << "You have dealt " << damageDealt << " damage.\n";
                    if(ninjaHealth < 0)
                    {
                        ++enemiesKilled;
                        enemiesKilledText.setString("Enemies killed: " + std::to_string(enemiesKilled));
                        enemiesKilledText.setOrigin(enemiesKilledText.getGlobalBounds().width/2.0f, enemiesKilledText.getGlobalBounds().height/2.0f);
                        enemiesKilledText.setPosition(width/2, height/12);
                        health += 8;
                        if(health > 100)
                            health = 100;
                        healthBoxHeroFill.setSize(sf::Vector2f(health/100*originalSize, originalHeight));
                        enemyAnimation = true;
                        smokePlume = true;
                        ninjaHealth = 0;
                    }
                    healthBoxNinjaFill.setSize(sf::Vector2f(ninjaHealth/ninjaHealthMax*originalSize, originalHeight));
                }
            }
        }

        window.clear();
        for(unsigned int i = 0; i < backgrounds.size(); ++i)
        {
            if(!freerun && movement >= 0)
            {
                backgrounds[i].move(-movement, 0);
            }

            if(sliding)
            {
                backgrounds[i].move(-DeltaTime*250, 0);
                knight.move(-DeltaTime/4, 0);
                hitbox.move(-DeltaTime/4, 0);
                sf::FloatRect bounds = knight.getGlobalBounds();
                bounds.left += 256;
                if(knight.getPosition().x < w8-256 || bounds.intersects(slideBoundary.getGlobalBounds()))
                {
                    sliding = false;
                    stationary = false;
                    freerun = false;
                }
            }

            window.draw(backgrounds[i]);
        }

        window.draw(knight);
        window.draw(ninja);
        if(!gameOver && !gameStart) window.draw(healthBoxHero);
        if(!gameOver && !gameStart) window.draw(healthBoxHeroFill);
        if(!gameOver && !gameStart) window.draw(healthBoxNinja);
        if(!gameOver && !gameStart) window.draw(healthBoxNinjaFill);
        if(!gameStart) window.draw(enemiesKilledText);
        if(gameStart) window.draw(spaceToBegin);
        if(gameOver) window.draw(gameOverText);

        for(unsigned int i = 0; i < fireballs.size(); ++i)
        {
            if(fireballCircles[i].getGlobalBounds().intersects(hitbox.getGlobalBounds()))
            {
                fireballs.erase(fireballs.begin() + i);
                fireballCircles.erase(fireballCircles.begin() + i);
                std::uniform_int_distribution<int> uni(ninjaDamageMin, ninjaDamageMax*1.5);
                double damageDealt = uni(rng);
                health -= damageDealt;
                std::cout << "The ninja hit you with a fireball and dealt " << damageDealt << " damage.\n";
                if(health < 0)
                {
                    heroAnimationStage = 0;
                    heroAnimation = true;
                    smokePlumeHero = true;
                    health = 0;
                }
                healthBoxHeroFill.setSize(sf::Vector2f(health/100*originalSize, originalHeight));
            }
            else
            {
                if(fireballs[i].getPosition().x < 0)
                {
                    fireballs.erase(fireballs.begin() + i);
                    fireballCircles.erase(fireballCircles.begin() + i);
                }
                else
                {
                    fireballTimers[i]+=DeltaTime;

                    if(fireballTimers[i] > fbAnimationDelay)
                    {
                        fireballTimers[0] = 0.0;
                        ++fireballAnimationStages[i];

                        switch(fireballAnimationStages[i])
                        {
                            case 1 : fireballs[i].setTexture(t_fb1);
                                     break;
                            case 2 : fireballs[i].setTexture(t_fb2);
                                     break;
                            case 3 : fireballs[i].setTexture(t_fb3);
                                     break;
                            case 4 : fireballs[i].setTexture(t_fb4);
                                     fireballAnimationStages[i] = 0;
                                     break;
                        }
                    }

                    fireballs[i].move(-DeltaTime*450, 0);
                    fireballCircles[i].move(-DeltaTime*450, 0);
                    window.draw(fireballs[i]);
                    //window.draw(fireballCircles[i]);
                }
            }
        }
        //window.draw(hitbox);
        //window.draw(ninjaHitbox);
        window.display();
    }

    return 0;
}
