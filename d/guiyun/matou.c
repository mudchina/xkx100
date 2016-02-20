// Room: /guiyun/matou.c
// Date: Nov.18 1998 by Winder
#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "码头");
	set("long", @LONG
这是一个在江南水乡极常见的码头，由粗糙的大青条石搭成。西面
似乎有一个极大的庄院。靠岸停有一艘大渔船(ship)，大篷斜挂，风帆
大张，看那样子不是为了出湖(hu)，倒象是征战用的。
LONG );
        set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("item_desc", ([
		"ship":"这是太湖水盗劫富济贫的战船。上去(shang ship)就出发。\n",
		"hu"  : HIC "\n近湖畔处有一叶小舟，舟上一个老梢公正在划桨，也许大声喊("
                         HIY "yell" HIC ")一声船\n家(" HIY "boat" HIC
                        ")就能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏水而过。\n" NOR,
	]));
	set("exits", ([
		"east" : __DIR__"road2",
	]));
	set("coor/x", 300);
	set("coor/y", -600);
	set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "湖");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得湖面上隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "艄公把踏脚板收了起来，竹篙一点，扁舟向湖心驶去。\n");
  set("leave_msg_in",   "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向湖心驶去。\n");
  set("come_msg_in",    "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n近湖畔处有一叶小舟，舟上一个老梢公正在划桨，也许大声喊("
                         HIY "yell" HIC ")一声船\n家(" HIY "boat" HIC
                        ")就能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏水而过。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
离岸渐远，四望空阔，真是莫知天地之在湖海，抑或是湖海之在天
地。老梢公在船尾悠闲地划着水。
LONG );
  set("to", "/d/yixing/taihu");
	setup();
}
void init()
{
	::init();
	add_action("do_shang", "shang");
}

int do_shang ( string arg )
{
	object ob ;
	string dir;
	if( !arg || arg !="ship" ) 
	{
		 tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		 return 1 ;
	}
	ob = this_player () ;
	message_vision("船上群盗一见$N上船，忙叫了一声：首领来了，开船喽！杀金狗去！\n", ob);
	message_vision("船上升起帆，船就向湖中航行。\n", ob);
	ob ->move("/d/guiyun/ship") ;
	tell_object(ob, CYN "你率船在湖上破浪前行，战旗猎猎.......\n" NOR ) ;
	call_out("rjinbing", 10 , ob );
	return 1 ;
}
void rjinbing( object ob )
{
	object ship, jinship;
	if(!( ship = find_object("/d/guiyun/ship")) )
		  ship = load_object("/d/guiyun/ship");
	if(!( jinship = find_object("/d/guiyun/jinship")) )
		  jinship = load_object("/d/guiyun/jinship");
	tell_object(ob , "战船在一阵阵喊杀声中撞上了另一艘大船。\n" ) ;
	ship->set("exits/out", "/d/guiyun/jinship" );
	jinship->set("exits/out", "/d/guiyun/ship" );
}
