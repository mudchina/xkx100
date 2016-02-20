// Room: /d/yueyang/matou.c
// Last Modifyed by Winder on Dec. 4 2001
#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "君山码头");
	set("long", @LONG
君山在岳阳西南三十里的洞庭湖中，是一座方圆不过三、四里的小
岛。原名洞府山，取意神仙“洞府之庭”。传说这座“洞庭山浮于水上
，其下有金堂数百间，玉女居之，四时闻金石丝竹之声，砌于山顶”。
这浪漫神话传说，不足为信。后因舜帝的两个妃子娥皇、女英葬于此，
屈原在《九歌》中称之为湘君和湘夫人，故后人将此山改名为君山。
    这里是君山码头，东面远远可以看到巍峨的岳阳楼，中间隔着洞庭
湖(hu)的万顷波涛。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("item_desc", ([
		"hu" : "
    洞庭湖“衔远山，吞长江，浩浩荡荡，横无际涯，渚清沙白，芳草
如茵，朝晖夕阴，气象万千。”自古以来，洞庭湖就以湖光山色吸引游
人，历代著名学家为之倾倒。唐李白诗云：“淡扫明湖开玉镜，丹青画
出是君山。”
    近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "dongting");
	set("coor/x", -1710);
	set("coor/y", 2270);
	set("coor/z", -20);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "湖");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得湖面上隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "艄公把踏脚板收了起来，竹篙一点，扁舟向湖心驶去。\n");
  set("leave_msg_in",   "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向湖心驶去。\n");
  set("come_msg_in",    "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n只见近岸处有一叶小舟，也许大声喊("
                         HIY "yell" HIC ")一声船家(" HIY "boat" HIC
                        ")就\n能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而过。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
一叶小舟，飘摇在洞庭湖湖面。泛舟湖心，“四顾疑无地，中流忽
有山”。举目望去，“烟波不动景沉沉，碧色全无翠色深。疑是水仙梳
洗处，一螺青黛镜中心。”那，就是由七十二峰组成的君山，峰峰灵秀，
不知陶醉了多少文人墨客。
LONG );
  set("to",         __DIR__"matou1");  // 船的终点 /*   必选   */
	setup();
}
