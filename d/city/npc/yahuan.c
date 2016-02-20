// yahuan.c 丫鬟

inherit NPC;
void create()
{
	set_name( "丫鬟", ({ "ya huan", "yahuan" }) );
	set( "title", "杨府" );
	set( "attribute", "peaceful" );
	set( "gender", "女性" );
	set( "age", 15 );
	set( "long", @LONG
一个丫鬟，长的小巧可爱，圆圆的脸上带笑看着你。
LONG);
    
	set( "str", 20 );
	set( "dex", 20 );
	set( "per", 22 );
	set( "combat_exp", 1000 );
    
	set( "inquiry", ([
        "杨府" : "嘻嘻，你不正在杨府吗？\n",
        "小玲珑山馆" : "就是杨府。\n",
        "扬州" : "扬州繁华甲天下！\n",
        "杨磊石" : "那是我家少爷。\n"
	]) );
    
	set("chat_chance", 20);
	set("chat_msg", ({
        "老爷说过不能随便和陌生人搭腔的。",
        "小女子有事，对不起了。",
    }) );
	setup();
	carry_object(__DIR__"obj/pink_cloth" )->wear();
	carry_object(__DIR__"obj/flower_shoe" )->wear();
}
