--**************Delaring constant variables*********************
--HELLO FRIENDS WELLCOME TO ---- CHANNEL TODAY WE GONNA LOOKING UP THE GAME ACTUALLY NOT LOOKING UP BUT MADING IT UP THE NAME OF GAME IS PING PONG 
--I HOPE YOU ALL HAVE PLAYED IT 

--LET ME SHOW YOU DEMO OF IT JUST WATCH OK--

-- SHOW HOW'S IT PLEASE TELL OK -- 
VIRTUAL_WIDTH = 395
VIRTUAL_HEIGHT = 216
WINDOW_WIDTH = 1300
WINDOW_HEIGHT = 710

PADLE_WIDTH = 6
PADLE_HEIGHT = 32
PADLE_SPEED = 140
gamestate = 'title'

LARGE_FONT = love.graphics.newFont(32)
SMALL_FONT = love.graphics.newFont(16)


BALL_SIZE = 5
push = require 'push'
player1 = {
    X = 10, Y = 10,score = 0
}
player2 = {
    X = VIRTUAL_WIDTH - 15,
    Y = VIRTUAL_HEIGHT -10  - PADLE_HEIGHT,
    score = 0
}

ball = {
    X = VIRTUAL_WIDTH/2 - BALL_SIZE/2,
    Y = VIRTUAL_HEIGHT/2 - BALL_SIZE/2,
    dx = 0,dy = 0
}

function love.load()
    math.randomseed(os.time())
    love.graphics.setDefaultFilter('nearest','nearest')
    push:setupScreen(VIRTUAL_WIDTH,VIRTUAL_HEIGHT,WINDOW_WIDTH,WINDOW_HEIGHT)
    resetBall()
end

function love.update(dt)--dt is the time between the two frames

    if love.keyboard.isDown('w') then
        player1.Y = player1.Y - PADLE_SPEED * dt
    elseif love.keyboard.isDown('z') then
        player1.Y = player1.Y + PADLE_SPEED * dt
    end
    if love.keyboard.isDown('up') then
        player2.Y = player2.Y - PADLE_SPEED * dt
    elseif love.keyboard.isDown('down') then
        player2.Y = player2.Y + PADLE_SPEED * dt
    end

    if gamestate == 'play' then
        ball.X = ball.X + ball.dx * dt
        ball.Y = ball.Y + ball.dy * dt
        if ball.X <= 0 then
            player2.score = player2.score + 1;
            
            resetBall()--To make random direction of ball
            gamestate = 'serve'
        else if ball.X >= VIRTUAL_WIDTH then
            player1.score = player1.score + 1;
           
            resetBall()
            gamestate = 'serve'
        end


        if ball.Y <= 0 then 
            ball.dy = -ball.dy
        elseif ball.Y >= VIRTUAL_HEIGHT-BALL_SIZE  then
            ball.dy = -ball.dy
        end

        if collides(player1,ball) then
            ball.dx = -ball.dx--1.02
            ball.X = player1.X + PADLE_WIDTH + 2
        elseif collides(player2,ball) then
            ball.dx = -ball.dx

            ball.X = player2.X - BALL_SIZE
        end

    end
    if player2.score >= 10 then
        gamestate = 'win2'
    elseif player1.score >= 10 then
        gamestate = 'win1'
    end
end
end
function love.keypressed(key)
    if key == 'escape' then
        love.event.quit();
    end
    if key == 'return' or key == 'enter' then
        if gamestate == 'title' then
            gamestate = 'serve'
        elseif gamestate == 'serve' then
            gamestate = 'play'
        end
    end


end

function love.draw()
    push:start()
    love.graphics.clear(40/255,45/255,52/255,255/255)

    if gamestate == 'title' then
        love.graphics.setFont(LARGE_FONT)
        love.graphics.printf('PING PONG',0,10,VIRTUAL_WIDTH,'center')
        love.graphics.setFont(SMALL_FONT)
        love.graphics.printf('Press ENTER to play',0,VIRTUAL_HEIGHT - 32,VIRTUAL_WIDTH,'center')
    end
    if gamestate == 'serve' then
        love.graphics.setFont(SMALL_FONT)
        love.graphics.printf('PRESS ENTER TO SERVE!',0,10,VIRTUAL_WIDTH,'center')
    end
    if gamestate == 'win1' then
        love.graphics.setFont(LARGE_FONT)
        love.graphics.printf('PLAYER 1 WINS',0,10,VIRTUAL_WIDTH,'center')
    elseif gamestate == 'win2' then
        love.graphics.setFont(LARGE_FONT)
        love.graphics.printf('PLAYER 2 WINS',0,10,VIRTUAL_WIDTH,'center')
    end
    love.graphics.setFont(LARGE_FONT)
    love.graphics.print(player1.score,VIRTUAL_WIDTH/2 - 50,VIRTUAL_HEIGHT/2 - 23);
    love.graphics.print(player2.score,VIRTUAL_WIDTH/2 + 20,VIRTUAL_HEIGHT/2 - 23);
    love.graphics.setFont(SMALL_FONT)

    love.graphics.rectangle('fill',player1.X,player1.Y,PADLE_WIDTH,PADLE_HEIGHT)
    love.graphics.rectangle('fill',player2.X,player2.Y,PADLE_WIDTH,PADLE_HEIGHT)
    love.graphics.circle('fill',ball.X,ball.Y,BALL_SIZE)
    love.window.setTitle("PING PONG")
    push:finish()

end
function collides(p,b)
    return not(p.X > b.X + BALL_SIZE or p.Y > b.Y + BALL_SIZE or b.X > p.X + PADLE_WIDTH or p.Y > b.Y + BALL_SIZE or b.X > p.X + PADLE_WIDTH or b.Y > p.Y + PADLE_HEIGHT)
end 
function resetBall()
    ball.X = VIRTUAL_WIDTH/2 - BALL_SIZE/2
    ball.Y = VIRTUAL_HEIGHT/2 - BALL_SIZE/2
    ball.dx = 60 +  math.random(60) --Random number between 1 and 60
    if  math.random(2)== 2 then
        ball.dx = -ball.dx
    end
    ball.dy = 30 + math.random(60)
    if math.random(2) == 2 then
        ball.dy = -ball.dy
    end
end