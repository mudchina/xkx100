string *food_name = ({
"翡翠烧卖", "鸭菜包子", "千层油糕", "芝麻包子", 
});

string ask_secret()
{
    string food =  food_name[ random( sizeof( food_name ) ) ];
    command( "en" );
    command( "think" );
    command( "tell " + (string)this_player()->query( "id" ) + 
        " 你帮我买个" + food );
    this_player()->set_temp( "kid_ask/" + query( "id" ), food );
    return "怎么样？帮我买了，我就告诉你！\n";
}

int accept_object( object me, object ob)
{
    string food, id = me->query( "id" );
    food = (string)me->query_temp( "kid_ask/" + query( "id" ) ) ;
    if ( food && food == ob->name() )
    {
        command( "grin " + id );
        command( "tell " + id + " 我的秘密是：我老爸叫" 
        + query( "papa_name" ) + "。" );
        command( "laugh1 " + id );
        me->delete_temp( "kid_ask/" + query( "id" ) );
        return 1;
    }
    command( "look " + id );
    command( "sigh " + id );
    return 0;
}

