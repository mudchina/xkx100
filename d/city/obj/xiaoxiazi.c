// xiaoxiazi.c
// 未调试完。 需要have_married这个标记
// 还是等结婚做好吧。

inherit ITEM;
inherit F_UNIQUE;

int opening();
int halt_opening();

void create()
{
    set_name( "小匣子", ({ "xiao xiazi", "xiazi", "box" }) );
    set_weight( 2000 );
    if ( clonep() )
        set_default_object( __FILE__ );
    else
    {
        set( "long", @LONG
这个匣子虽小，却入手很沉，不知道是什么材料制成的。匣子表面上刻着一些神
秘的花纹，隐隐泛着柔和的红光，看上去有些奇异。
LONG
        );
        set( "unit", "个" );
        set( "value", 40 );
    }
    setup();
}

void init()
{
    add_action( "do_open_box", ({ "open", "kai" }) );
}

int do_open_box( string arg )
{
    object me = this_player();

    // 计划 : 如果是结婚的一对合作打开这个匣子，能得到护花铃。
    // 没有结婚根本打不开。

    if ( !arg ) return 0;
    if ( !me->can_act() ) return 0;
    if ( !this_object()->id( arg ) ) return 0;

    if ( query ( "opened" ) ) return notify_fail( "这个匣子已经打开了。" );

    if ( !me->query( "have_married" ) )
        return notify_fail( "你试图打开这个匣子，当你的手一触到匣子，感觉到一股奇异的力量将你的手推开。\n" );
    else
    {
        me->set_temp( "open_box_mark", 51 );
        if ( !query_temp ( "open_box" ) )
        {
            set_temp( "open_box", me->query( "have_married") );
        }
        {
            set_temp( "both_open", 1 ); 
        }
        me->start_busy( (:opening:), (:halt_opening:) );
        return 1;
    }
    return 0;
}

int opening()
{
    object ob, me = this_player();
    int mark = me->query_temp( "open_box_mark" );

    if ( mark > 50 )
    {
        message_vision( "$N伸手按在匣子上。\n", me );
        write ( "你突然感到匣子里有一种奇异的力量吸引着你的手掌。\n" );
        me->add_temp( "open_box_mark", -10 );
        return 1;
    }

    if ( mark < 10 ) 
    {
        // 很遗憾了，时间过了。
        message_vision( "时间过了", me );
        me->delete_temp( "open_box_mark" );
        remove_call_out( "del_temp" );
        call_out( "del_temp" , 1 );
        return 0;
    }

    me->add_temp( "open_box_mark", -10 );
    if ( !query_temp( "both_open" ) )
    {
        // 接着按着这个匣子吧。
        message_vision( "还按着", me );
        return 1;
    }
    // 该合作打开这个匣子了。
    else if ( query_temp( "open_box" ) != me->query( "have_married" ) 
        && query_temp( "open_box" ) != me)
    {
        // 不是一对夫妻，却妄图打开这个匣子，该怎么处理呢？
        // 一定要给惩罚！grin
        message_vision( "", me );
        me->delete_temp( "open_box_mark" );
        remove_call_out( "del_temp" );
        call_out( "del_temp", 1 );
        return 0;
    }
    else
    {
        // 哈哈，终于是一对夫妻在开这个匣子了。:-)
        message_vision( "", me );
        // new一双护花铃，夫妻俩一人一个。
        ob = new( __DIR__"huhua_ling" );
        ob->move(me);
        me->delete_temp( "open_box_mark" );
        remove_call_out( "del_temp" );
        call_out( "del_temp", 2 );
        return 0;
    }
    return 0;
}

int halt_opening()
{
    object me = this_player();
    write( "你放弃开启这个匣子的企图了。\n" );
    me->delete_temp( "open_box_mark" );
    remove_call_out( "del_temp" );
    call_out( "del_temp" , 1 );
    return 1;
}

void del_temp()
{
    if ( query_temp( "open_box" ) )
        delete_temp( "open_box" );
}

