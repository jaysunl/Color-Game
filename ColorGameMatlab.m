% Exercise 5a
% Button pushed function: StartButton
function StartButtonPushed(app, event)
    app.Lamp_Yours.Color = [0,0,0]; %set your lamp to black (off)
    lamp_color = rand*7;
    if (lamp_color < 1)
        app.Lamp_Target.Color = [1,0,0]; %set target lamp to red
    elseif (lamp_color < 2)
        app.Lamp_Target.Color = [0,1,0]; %set target lamp to green
    elseif (lamp_color < 3)
        app.Lamp_Target.Color = [0,0,1]; %set target lamp to blue
    elseif (lamp_color < 4)
        app.Lamp_Target.Color = [1,1,1]; %set target lamp to white
    elseif (lamp_color < 5)
        app.Lamp_Target.Color = [1,1,0]; %set target lamp to yellow
    elseif (lamp_color < 6)
        app.Lamp_Target.Color = [1,0,1]; %set target lamp to purple
    elseif (lamp_color < 7)
        app.Lamp_Target.Color = [0,1,1]; %set target lamp to cyan
    end
end

% Button pushed function: RedButton
function RedButtonPushed(app, event)
    if (app.Lamp_Yours.Color(1) == 0)
        app.Lamp_Yours.Color(1) = app.Lamp_Yours.Color(1) + 1; %add 1 to the red value of your lamp
    end
end

% Button pushed function: GreenButton
function GreenButtonPushed(app, event)
    if (app.Lamp_Yours.Color(2) == 0)
        app.Lamp_Yours.Color(2) = app.Lamp_Yours.Color(2) + 1; %add 1 to the green value of your lamp
    end
end

% Button pushed function: BlueButton
function BlueButtonPushed(app, event)
    if (app.Lamp_Yours.Color(3) == 0)
        app.Lamp_Yours.Color(3) = app.Lamp_Yours.Color(3) + 1; %add 1 to the blue value of your lamp
    end
end

% Button pushed function: ResetButton
function ResetButtonPushed(app, event)
    app.Lamp_Yours.Color = [0,0,0]; %set your lamp to black (off)
end

% Button pushed function: WhiteButton
function WhiteButtonPushed(app, event)
    app.Lamp_Yours.Color = [1,1,1]; %set your lamp to white
end

% Exercise 5b
% Button pushed function: StartButton
function StartButtonPushed(app, event)
    app.Lamp_Yours.Color = [0,0,0]; %set your lamp to black (off)
    app.Lamp.Color = [0,1,0]; %set the indicator lamp to green (start)
    app.scoreEditField.Value = 0;
    lamp_color = rand*7;
    while (app.Lamp.Color(2) == 1)
        if (lamp_color < 1)
            app.Lamp_Target.Color = [1,0,0]; %set target lamp to red
        elseif (lamp_color < 2)
            app.Lamp_Target.Color = [0,1,0]; %set target lamp to green
        elseif (lamp_color < 3)
            app.Lamp_Target.Color = [0,0,1]; %set target lamp to blue
        elseif (lamp_color < 4)
            app.Lamp_Target.Color = [1,1,1]; %set target lamp to white
        elseif (lamp_color < 5)
            app.Lamp_Target.Color = [1,1,0]; %set target lamp to yellow
        elseif (lamp_color < 6)
            app.Lamp_Target.Color = [1,0,1]; %set target lamp to purple
        elseif (lamp_color < 7)
            app.Lamp_Target.Color = [0,1,1]; %set target lamp to cyan
        end
        pause(0.1);
        if (app.Lamp_Yours.Color * [2;4;8] == app.Lamp_Target.Color * [2;4;8])
            app.scoreEditField.Value = app.scoreEditField.Value + 1; %add 1 to the scoreboard
            app.Lamp_Yours.Color =[0,0,0]; %reset your lamp’s color to black (off)
            lamp_color = rand*7;
        end
    end
end

% Button pushed function: StopButton
function StopButtonPushed(app, event)
    app.Lamp.Color =[1,0,0]; %set the indicator lamp to red (stop)
end

% Exercise 5c
% Button pushed function: StartButton
function StartButtonPushed(app, event)
    app.Lamp_Yours.Color = [0,0,0]; %set your lamp to black (off)
    app.Lamp.Color = [0,1,0]; %set the indicator lamp to green (start)
    app.scoreEditField.Value = 0;
    lamp_color = rand*7;
    tic;
    while (app.Lamp.Color(2) == 1)
        if (lamp_color < 1)
            app.Lamp_Target.Color = [1,0,0]; %set target lamp to red
        elseif (lamp_color < 2)
            app.Lamp_Target.Color = [0,1,0]; %set target lamp to green
        elseif (lamp_color < 3)
            app.Lamp_Target.Color = [0,0,1]; %set target lamp to blue
        elseif (lamp_color < 4)
            app.Lamp_Target.Color = [1,1,1]; %set target lamp to white
        elseif (lamp_color < 5)
            app.Lamp_Target.Color = [1,1,0]; %set target lamp to yellow
        elseif (lamp_color < 6)
            app.Lamp_Target.Color = [1,0,1]; %set target lamp to purple
        elseif (lamp_color < 7)
            app.Lamp_Target.Color = [0,1,1]; %set target lamp to cyan
        end
        pause(0.1);
        if (app.Lamp_Yours.Color * [2;4;8] == app.Lamp_Target.Color * [2;4;8])
            app.scoreEditField.Value = app.scoreEditField.Value + 1; %add 1 to the scoreboard
            app.Lamp_Yours.Color =[0,0,0]; %reset your lamp’s color to black (off)
            lamp_color = rand*7;
        end
        if(toc >= 60|| app.Lamp.Color(2) == 0)
            break; %leave the while loop
        end
    end
end
