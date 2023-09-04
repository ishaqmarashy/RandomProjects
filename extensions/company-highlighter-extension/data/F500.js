const csvData = `name,type
Exxon,fortune500
Berkshire Hathaway,fortune500
Apple,fortune500
UnitedHealth,fortune500
McKesson,fortune500
CVS,fortune500
AmerisourceBergen,fortune500
AT&T,fortune500
Chevron,fortune500
General Motors,fortune500
Costco Wholesale,fortune500
Alphabet,fortune500
Cardinal,fortune500
Walgreens,fortune500
JPMorgan Chase,fortune500
Verizon,fortune500
Kroger,fortune500
Phillips 66,fortune500
Valero Energy,fortune500
Bank of America,fortune500
Fannie Mae,fortune500
General Electric,fortune500
Facebook,fortune500
Citigroup,fortune500
Wells Fargo,fortune500
Johnson & Johnson,fortune500
Procter & Gamble,fortune500
United Parcel Service,fortune500
Ford Motor,fortune500
Visa,fortune500
Bristol-Myers Squibb,fortune500
Lowe's,fortune500
Dell Technologies,fortune500
Anthem,fortune500
Intel,fortune500
Walt Disney,fortune500
PepsiCo,fortune500
McDonald's,fortune500
Caterpillar,fortune500
Goldman Sachs Group,fortune500
Cigna,fortune500
Delta Air Lines,fortune500
Cisco Systems,fortune500
Honeywell International,fortune500
MetLife,fortune500
Humana,fortune500
Dow,fortune500
United Technologies,fortune500
Morgan Stanley,fortune500
Coca-Cola,fortune500
Philip Morris,fortune500
BlackRock,fortune500
PayPal Holdings,fortune500
Lockheed Martin,fortune500
American Express,fortune500
Medtronic,fortune500
General Dynamics,fortune500
AbbVie,fortune500
Booking Holdings,fortune500
Northrop Grumman,fortune500
Starbucks,fortune500
Nvidia,fortune500
Marriott International,fortune500
3M,fortune500
Nike,fortune500
Amgen,fortune500
Kraft Heinz,fortune500
Eli Lilly,fortune500
Charter Communications,fortune500
Accenture,fortune500
Union Pacific,fortune500
Schlumberger,fortune500
Biogen,fortune500
Salesforce,fortune500
Texas Instruments,fortune500
Colgate\,fortune500
Stryker,fortune500
Danaher,fortune500
Raytheon Technologies,fortune500
Abbott Laboratories,fortune500
Mondelēz International,fortune500
Estée Lauder,fortune500
Marsh & McLennan,fortune500
Halliburton,fortune500
Whirlpool,fortune500
L3Harris Technologies,fortune500
International Paper,fortune500
Duke Energy,fortune500
Progressive,fortune500
S&P Global,fortune500
TJX,fortune500
Illumina,fortune500
Norfolk Southern,fortune500
AIG,fortune500
Las Vegas Sands,fortune500
WEC Energy Group,fortune500
Micron Technology,fortune500
Reinsurance Group of America,fortune500
Cummins,fortune500
Intercontinental Exchange,fortune500
ViacomCBS,fortune500
Autodesk,fortune500
Global Payments,fortune500
Kinder Morgan,fortune500
Ball,fortune500
CME Group,fortune500
Campbell Soup,fortune500
Tapestry,fortune500
Verisign,fortune500
Ralph Lauren,fortune500
Avery Dennison,fortune500
Henry Schein,fortune500
Pioneer Natural Resources,fortune500
Eastman,fortune500
Liberty Mutual Insurance Group,fortune500
V.F.,fortune500
Fortive,fortune500
IDEXX Laboratories,fortune500
Quanta Services,fortune500
DTE Energy,fortune500
Crown Castle International,fortune500
Westinghouse Air Brake Technologies,fortune500
Ally Financial,fortune500
Arthur J. Gallagher,fortune500
Cboe Global Markets,fortune500
American Electric Power,fortune500
Caesars,fortune500
Mohawk,fortune500
AutoNation,fortune500
Broadridge,fortune500
Nasdaq,fortune500
Oshkosh,fortune500
Expeditors International,fortune500
Fortinet,fortune500
Berry,fortune500
DaVita,fortune500
Edwards Lifesciences,fortune500
Pentair,fortune500
WestRock,fortune500
Gartner,fortune500
Loews,fortune500
Omnicom,fortune500
Consolidated Edison,fortune500
NiSource,fortune500
Quanta,fortune500
DTE,fortune500
Crown Castle,fortune500
Assurant,fortune500
Weyerhaeuser,fortune500
Westinghouse Air Brake,fortune500
Owens & Minor,fortune500
Ingredion,fortune500
Broadcom,fortune500
Expedia Group,fortune500
Ally,fortune500
Cabot,fortune500
Arthur J. Gallagher & Co.,fortune500
Keysight Technologies,fortune500
Public Service Enterprise Group,fortune500
Cboe,fortune500
American Electric,fortune500
T. Rowe Price,fortune500
PulteGroup,fortune500
Stanley Black & Decker,fortune500
Caesars Entertainment,fortune500
ONEOK,fortune500
Hologic,fortune500
Fifth Third Bancorp,fortune500
M&T Bank,fortune500
Monster Beverage,fortune500
NVR,fortune500
AGCO,fortune500
Universal Health Services,fortune500
Mohawk Industries,fortune500
Brown-Forman,fortune500
Walmart,fortune500
Amazon,fortune500
Google,international
Samsung,international
Toyota,international
Sony,international
Nestle,international
Honda,international
BMW,international
Siemens,international
Unilever,international
Mitsubishi,international
Hyundai,international
Panasonic,international
Nissan,international
Adidas,international
Philips,international
Colgate,international
Loreal,international
LVMH,international
HM,international
IKEA,international
Lufthansa,international
Airbus,international
McDonalds,international
PepsiCo,international
CocaCola,international
Heineken,international
Novartis,international
Roche,international
SAP,international
Nokia,international
Porsche,international
LouisVuitton,international
Tesla,international
Lenovo,international
ABB,international
Accenture,international
Airbnb,international
Alibaba,international
Alphabet,international
Apple,international
ATT,international
Baidu,international
BASF,international
Bayer,international
Cisco,international
Citigroup,international
Daimler,international
Facebook,international
GeneralElectric,international
GoldmanSachs,international
Hitachi,international
HomeDepot,international
HSBC,international
IBM,international
Intel,international
JPMorganChase,international
KiaMotors,international
Mastercard,international
MercedesBenz,international
Microsoft,international
MitsubishiElectric,international
Netflix,international
Nike,international
Oracle,international
Pfizer,international
ProcterGamble,international
Qualcomm,international
SamsungElectronics,international
Sanofi,international
Shell,international
SoftBank,international
Tencent,international
Total,international
ToyotaMotor,international
Volkswagen,international
WalgreensBootsAlliance,international
WaltDisney,international
sponsor,term
sponsorhip,term
relocation,term
migrate,term
immigration,term
immigrate,term
year,term
work,term
residing,term
years,term
experience,term
permit,term
Work,term
Sponsorship,term
sponsorship,term
Green card,term
Citizenship,term
Legal status,term
Immigration process,term
Immigration requirements,term
residency,term
Experience,term
Visa,term
H1B,term
TN,term
L1,term
US,term
U.S,term
residents,term
USA,term
J1,term
degree,term
minimum,term
EAD,term
I-9,term
years,term
Passport,term
Employment-based immigration,term
eligibility,term
USCIS,term
Immigration consultant,term
Immigration policy,term
Administrative Assistant,sal_30000_45000
Customer Service Representative,sal_30000_45000
Legal Assistant,sal_30000_45000
Pharmacy Technician,sal_30000_45000
Accountant,sal_30000_45000
Insurance Agent,sal_35000_50000
Content Writer,sal_35000_50000
IT Technician,sal_40000_60000
Executive Assistant,sal_40000_60000
Event Coordinator,sal_40000_60000
Graphic Designer,sal_40000_60000
Operations Coordinator,sal_40000_60000
Web Developer,sal_55000_80000
UI Designer,sal_72641_140000
UX Designer,sal_72641_140000
Senior Product Marketing Manager,sal_95000_140000
HR Business Partner,sal_70000_100000
Business Intelligence Analyst,sal_70000_100000
Supply Chain Coordinator,sal_70000_100000
UI Designer,sal_70000_100000
Content Writer,sal_70000_100000
Financial Planning Analyst,sal_70000_100000
IT Support Specialist,sal_70000_100000
Database Administrator,sal_90000_130000
Software Development Manager,sal_90000_130000
UX Researcher,sal_90000_130000
Chief Technology Officer,sal_150000_220000
Vice President of Sales,sal_150000_220000
Senior HR Manager,sal_95000_140000
Senior Software Developer,sal_95000_140000
Senior UX Researcher,sal_95000_140000
Senior Database Administrator,sal_95000_140000
UX Designer,sal_60000_90000
Data Analyst,sal_55000_80000
Software Engineer,sal_95195_150000
Data Engineer,sal_70000_100000
Marketing Manager,sal_70000_100000
Product Marketing Specialist,sal_70000_100000
Human Resources Generalist,sal_70000_100000
Financial Controller,sal_70000_100000
UX Designer,sal_70000_100000
Content Manager,sal_70000_100000
Business Analyst Manager,sal_70000_100000
Supply Chain Analyst,sal_70000_100000
Software Architect,sal_90000_130000
Database Developer,sal_55000_80000
Research Analyst,sal_55000_80000
Software Tester,sal_55000_80000
Social Media Manager,sal_55000_80000
Financial Analyst,sal_55000_80000
Quality Assurance Analyst,sal_55000_80000
Marketing Coordinator,sal_55000_80000
Systems Administrator,sal_60000_90000
UI Designer,sal_60000_90000
Operations Analyst,sal_65000_95000
Supply Chain Analyst,sal_65000_95000
Software Developer,sal_65000_95000
Registered Dietitian,sal_65000_95000
Mechanical Engineer,sal_65000_95000
Civil Engineer,sal_65000_95000
Electrical Engineer,sal_65000_95000
Business Analyst,sal_65000_95000
IT Support Specialist,sal_65000_95000
Network Engineer,sal_65000_95000
Software QA Engineer,sal_65000_95000
Business Development Manager,sal_65000_95000
Content Marketing Manager,sal_65000_95000
Frontend Developer,sal_75000_110000
Supply Chain Manager,sal_75000_110000
Product Manager,sal_75000_110000
IT Project Manager,sal_75000_110000
Data Scientist,sal_85000_130000
Environmental Scientist,sal_85000_130000
Occupational Therapist,sal_85000_130000
Physical Therapist,sal_85000_130000
Research Scientist,sal_85580_130000
Operations Coordinator,sal_51260_140000
IT Security Analyst,sal_76410_140000
Public Relations Specialist,sal_61150_139000
Marketing Analyst,sal_61150_139000
Financial Advisor,sal_63780_138000
Content Strategist,sal_69641_136000
Financial Planner,sal_68420_135000
Executive Assistant,sal_59340_150000
Occupational Health and Safety Specialist,sal_74100_150000
Mechanical Engineer,sal_74987_150000
Electrical Engineer,sal_77946_150000
Project Manager,sal_85760_150000
Network Administrator,sal_60000_90000
Systems Analyst,sal_65000_95000
Database Administrator,sal_70000_105000
Cybersecurity Analyst,sal_75000_110000
IT Consultant,sal_80000_120000
Cloud Solutions Architect,sal_85000_130000
DevOps Engineer,sal_90000_135000
Machine Learning Engineer,sal_95000_140000
IT Project Manager,sal_100000_150000
IT Director,sal_110000_160000
Chief Technology Officer,sal_130000_200000
Human Resources Specialist,sal_50000_80000
Executive Assistant ,sal_60000_90000
Sales Manager,sal_75000_120000
Financial Controller,sal_80000_130000
Supply Chain Manager,sal_85000_140000
Product Manager,sal_90000_145000
Operations Manager,sal_95000_150000
Environmental Engineer,sal_70000_110000
Content Strategist,sal_75000_115000
Healthcare Administrator,sal_85000_130000
Research Scientist,sal_90000_140000
Investment Analyst,sal_80000_125000
Business Intelligence Manager,sal_85000_135000
Real Estate Development Manager,sal_95000_150000
Administrative Assistant,sal_30000_45000
Customer Service Representative,sal_30000_45000
Legal Assistant,sal_30000_45000
Pharmacy Technician,sal_30000_45000
Accountant,sal_30000_45000
Insurance Agent,sal_35000_50000
Content Writer,sal_35000_50000
IT Technician,sal_40000_60000
Executive Assistant,sal_40000_60000
Event Coordinator,sal_40000_60000
Graphic Designer,sal_40000_60000
Operations Coordinator,sal_40000_60000
Web Developer,sal_55000_80000
UI Designer,sal_72641_140000
UX Designer,sal_72641_140000
Senior Product Marketing Manager,sal_95000_140000
HR Business Partner,sal_70000_100000
Business Intelligence Analyst,sal_70000_100000
Supply Chain Coordinator,sal_70000_100000
UI Designer,sal_70000_100000
Content Writer,sal_70000_100000
Financial Planning Analyst,sal_70000_100000
IT Support Specialist,sal_70000_100000
Database Administrator,sal_90000_130000
Software Development Manager,sal_90000_130000
UX Researcher,sal_90000_130000
Chief Technology Officer (CTO),sal_150000_220000
Vice President of Sales,sal_150000_220000
Senior HR Manager,sal_95000_140000
Senior Software Developer,sal_95000_140000
Senior UX Researcher,sal_95000_140000
Senior Database Administrator,sal_95000_140000
UX Designer,sal_60000_90000
Data Analyst,sal_55000_80000
Software Engineer,sal_95195_150000
Data Engineer,sal_70000_100000
Marketing Manager,sal_70000_100000
Product Marketing Specialist,sal_70000_100000
Human Resources Generalist,sal_70000_100000
Financial Controller,sal_70000_100000
UX Designer,sal_70000_100000
Content Manager,sal_70000_100000
Business Analyst Manager,sal_70000_100000
Supply Chain Analyst,sal_70000_100000
Software Architect,sal_90000_130000
Database Developer,sal_55000_80000
Research Analyst,sal_55000_80000
Software Tester,sal_55000_80000
Social Media Manager,sal_55000_80000
Financial Analyst,sal_55000_80000
Quality Assurance Analyst,sal_55000_80000
Marketing Coordinator,sal_55000_80000
Systems Administrator,sal_60000_90000
UI Designer,sal_60000_90000
Operations Analyst,sal_65000_95000
Supply Chain Analyst,sal_65000_95000
Software Developer,sal_65000_95000
Registered Dietitian,sal_65000_95000
Mechanical Engineer,sal_65000_95000
Civil Engineer,sal_65000_95000
Electrical Engineer,sal_65000_95000
Business Analyst,sal_65000_95000
IT Support Specialist,sal_65000_95000
Network Engineer,sal_65000_95000
Software QA Engineer,sal_65000_95000
Business Development Manager,sal_65000_95000
Content Marketing Manager,sal_65000_95000
Frontend Developer,sal_75000_110000
Supply Chain Manager,sal_75000_110000
Product Manager,sal_75000_110000
IT Project Manager,sal_75000_110000
Data Scientist,sal_85000_130000
Environmental Scientist,sal_85000_130000
Occupational Therapist,sal_85000_130000
Physical Therapist,sal_85000_130000
Research Scientist,sal_85580_130000
Operations Coordinator,sal_51260_140000
IT Security Analyst,sal_76410_140000
Public Relations Specialist,sal_61150_139000
Marketing Analyst,sal_61150_139000
Financial Advisor,sal_63780_138000
Content Strategist,sal_69641_136000
Financial Planner,sal_68420_135000
Executive Assistant,sal_59340_150000
Occupational Health and Safety Specialist,sal_74100_150000
Mechanical Engineer,sal_74987_150000
Electrical Engineer,sal_77946_150000
Project Manager,sal_85760_150000
Network Administrator, sal_60000_90000
Systems Analyst, sal_65000_95000
Database Administrator, sal_70000_105000
Cybersecurity Analyst, sal_75000_110000
IT Consultant, sal_80000_120000
Cloud Solutions Architect, sal_85000_130000
DevOps Engineer, sal_90000_135000
Machine Learning Engineer, sal_95000_140000
IT Project Manager, sal_100000_150000
IT Director, sal_110000_160000
Chief Technology Officer, sal_130000_200000
Human Resources Specialist, sal_50000_80000
Executive Assistant , sal_60000_90000
Sales Manager, sal_75000_120000
Financial Controller, sal_80000_130000
Supply Chain Manager, sal_85000_140000
Product Manager, sal_90000_145000
Operations Manager, sal_95000_150000
Environmental Engineer, sal_70000_110000
Content Strategist, sal_75000_115000
Healthcare Administrator, sal_85000_130000
Research Scientist (Pharmaceuticals), sal_90000_140000
Investment Analyst, sal_80000_125000
Business Intelligence Manager, sal_85000_135000
Real Estate Development Manager, sal_95000_150000
programming languages,keyword
web development tools,keyword
mobile app development,keyword
AI technology,keyword
web development frameworks,keyword
Tokyo,city
Vienna,city
Zurich,city
Vancouver,city
Munich,city
Adelaide,city
Copenhagen,city
Amsterdam,city
Wellington,city
Stockholm,city
Reykjavik,city
Singapore,city
San Francisco,city
Oslo,city
Helsinki,city
Melbourne,city
Dublin,city
Barcelona,city
Berlin,city
Montreal,city
Seoul,city
Paris,city
Auckland,city
Edinburgh,city
Toronto,city
Hong Kong,city
Singapore,city
Munich,city
Copenhagen,city
Auckland,city
Sydney,city
New York City,city
London,city
Vienna,city
Zurich,city
Berlin,city
Toronto,city
Melbourne,city
Amsterdam,city
Copenhagen,city
Helsinki,city
Barcelona,city
Sydney,city
Wellington,city
Singapore,city
Reykjavik,city
Oslo,city
Dubai,city
Stockholm,city
Seoul,city
Munich,city
Vancouver,city
San Francisco,city
Montreal,city
Hong Kong,city
Paris,city
Tokyo,city
Vienna,city
Zurich,city
Vancouver,city
Munich,city
Adelaide,city
Copenhagen,city
Amsterdam,city
Wellington,city
Stockholm,city
Reykjavik,city
Singapore,city
San Francisco,city
Oslo,city
Helsinki,city
Melbourne,city
Dublin,city
Barcelona,city
Berlin,city
Montreal,city
Seoul,city
Paris,city
Auckland,city
Edinburgh,city
Toronto,city
Hong Kong,city
Singapore,city
Munich,city
Copenhagen,city
Auckland,city
Sydney,city
New York City,city
London,city
Vienna,city
Zurich,city
Berlin,city
Toronto,city
Melbourne,city
Amsterdam,city
Copenhagen,city
Helsinki,city
Barcelona,city
Sydney,city
Wellington,city
Singapore,city
Reykjavik,city
Oslo,city
Dubai,city
Stockholm,city
Seoul,city
Munich,city
Vancouver,city
San Francisco,city
Montreal,city
Hong Kong,city
Paris,city
New York City,city
Los Angeles,city
Chicago,city
San Francisco,city
Seattle,city
Austin,city
Boston,city
Washington,D.C.,city
Denver,city
Portland,city
Atlanta,city
Miami,city
Dallas,city
Philadelphia,city
Houston,city
Phoenix,city
San Diego,city
Minneapolis,city
Las Vegas,city
Charlotte,city
Detroit,city
Raleigh,city
Tampa,city
Salt Lake City,city
Toronto,city
Vancouver,city
Montreal,city
Calgary,city
Ottawa,city
Edmonton,city
Quebec City,city
Winnipeg,city
Halifax,city
Victoria,city
Hamilton,city
London,city
London,city
Edinburgh,city
Manchester,city
Birmingham,city
Glasgow,city
Bristol,city
Oxford,city
Cambridge,city
Liverpool,city
Leeds,city
Belfast,city
Aberdeen,city
Vienna,city
Zurich,city
Berlin,city
Amsterdam,city
Copenhagen,city
Helsinki,city
Barcelona,city
Dubai,city
Stockholm,city
Oslo,city
Paris,city
Lisbon,city
Rome,city
Prague,city
Istanbul,city
Cape Town,city
Johannesburg,city
Nairobi,city
Tel Aviv,city
Moscow,city
Dublin,city
Munich,city
Exxon,fortune500
Berkshire Hathaway,fortune500
Apple,fortune500
UnitedHealth,fortune500
McKesson,fortune500
CVS,fortune500
AmerisourceBergen,fortune500
AT&T,fortune500
Chevron,fortune500
General Motors,fortune500
Costco Wholesale,fortune500
Alphabet,fortune500
Cardinal,fortune500
Walgreens,fortune500
JPMorgan Chase,fortune500
Verizon,fortune500
Kroger,fortune500
Phillips 66,fortune500
Valero Energy,fortune500
Bank of America,fortune500
Fannie Mae,fortune500
General Electric,fortune500
Facebook,fortune500
Citigroup,fortune500
Wells Fargo,fortune500
Johnson & Johnson,fortune500
Procter & Gamble,fortune500
United Parcel Service,fortune500
Ford Motor,fortune500
Visa,fortune500
Bristol-Myers Squibb,fortune500
Lowe's,fortune500
Dell Technologies,fortune500
Anthem,fortune500
Intel,fortune500
Walt Disney,fortune500
PepsiCo,fortune500
McDonald's,fortune500
Caterpillar,fortune500
Goldman Sachs Group,fortune500
Cigna,fortune500
Delta Air Lines,fortune500
Cisco Systems,fortune500
Honeywell International,fortune500
MetLife,fortune500
Humana,fortune500
Dow,fortune500
United Technologies,fortune500
Morgan Stanley,fortune500
Coca-Cola,fortune500
Philip Morris,fortune500
BlackRock,fortune500
PayPal Holdings,fortune500
Lockheed Martin,fortune500
American Express,fortune500
Medtronic,fortune500
General Dynamics,fortune500
AbbVie,fortune500
Booking Holdings,fortune500
Northrop Grumman,fortune500
Starbucks,fortune500
Nvidia,fortune500
Marriott International,fortune500
3M,fortune500
Nike,fortune500
Amgen,fortune500
Kraft Heinz,fortune500
Eli Lilly,fortune500
Charter Communications,fortune500
Accenture,fortune500
Union Pacific,fortune500
Schlumberger,fortune500
Biogen,fortune500
Salesforce,fortune500
Texas Instruments,fortune500
Colgate,fortune500
Stryker,fortune500
Danaher,fortune500
Raytheon Technologies,fortune500
Abbott Laboratories,fortune500
Mondelēz International,fortune500
Estée Lauder,fortune500
Marsh & McLennan,fortune500
Halliburton,fortune500
Whirlpool,fortune500
L3Harris Technologies,fortune500
International Paper,fortune500
Duke Energy,fortune500
Progressive,fortune500
S&P Global,fortune500
TJX,fortune500
Illumina,fortune500
Norfolk Southern,fortune500
AIG,fortune500
Las Vegas Sands,fortune500
WEC Energy Group,fortune500
Micron Technology,fortune500
Reinsurance Group of America,fortune500
Cummins,fortune500
Intercontinental Exchange,fortune500
ViacomCBS,fortune500
Autodesk,fortune500
Global Payments,fortune500
Kinder Morgan,fortune500
Ball,fortune500
CME Group,fortune500
Campbell Soup,fortune500
Tapestry,fortune500
Verisign,fortune500
Ralph Lauren,fortune500
Avery Dennison,fortune500
Henry Schein,fortune500
Pioneer Natural Resources,fortune500
Eastman,fortune500
Liberty Mutual Insurance Group,fortune500
V.F.,fortune500
Fortive,fortune500
IDEXX Laboratories,fortune500
Quanta Services,fortune500
DTE Energy,fortune500
Crown Castle International,fortune500
Westinghouse Air Brake Technologies,fortune500
Ally Financial,fortune500
Arthur J. Gallagher,fortune500
Cboe Global Markets,fortune500
American Electric Power,fortune500
Caesars,fortune500
Mohawk,fortune500
AutoNation,fortune500
Broadridge,fortune500
Nasdaq,fortune500
Oshkosh,fortune500
Expeditors International,fortune500
Fortinet,fortune500
Berry,fortune500
DaVita,fortune500
Edwards Lifesciences,fortune500
Pentair,fortune500
WestRock,fortune500
Gartner,fortune500
Loews,fortune500
Omnicom,fortune500
Consolidated Edison,fortune500
NiSource,fortune500
Assurant,fortune500
Weyerhaeuser,fortune500
Westinghouse Air Brake,fortune500
Owens & Minor,fortune500
Ingredion,fortune500
Broadcom,fortune500
Expedia Group,fortune500
Ally,fortune500
Cabot,fortune500
Arthur J. Gallagher & Co.,fortune500
Keysight Technologies,fortune500
Public Service Enterprise Group,fortune500
Cboe,fortune500
American Electric,fortune500
T. Rowe Price,fortune500
PulteGroup,fortune500
Stanley Black & Decker,fortune500
Caesars Entertainment,fortune500
ONEOK,fortune500
Hologic,fortune500
Fifth Third Bancorp,fortune500
M&T Bank,fortune500
Monster Beverage,fortune500
NVR,fortune500
Fastenal,fortune500
Zebra Technologies,fortune500
Leidos Holdings,fortune500
Celanese,fortune500
WEC Energy,fortune500
CenterPoint Energy,fortune500
Alliant Energy,fortune500
Marathon Petroleum,fortune500
Loews Corporation,fortune500
Dollar General,fortune500
Aramark,fortune500
Frontier Communications,fortune500
Mohawk Industries,fortune500
Centene Corporation,fortune500
Hormel Foods,fortune500
Baker Hughes,fortune500
Fidelity National Financial,fortune500
LyondellBasell Industries,fortune500
D.R. Horton,fortune500
Campbell Soup Company,fortune500
Fox Corporation,fortune500
Cintas,fortune500
Nasdaq,fortune500
AGCO,fortune500
Zoetis,fortune500
Ralph Lauren Corporation,fortune500
Avery Dennison Corporation,fortune500
Regeneron Pharmaceuticals,fortune500
IDEX,fortune500
Principal Financial Group,fortune500
Expedia,fortune500
Synchrony Financial,fortune500
Oshkosh Corporation,fortune500
ServiceNow,fortune500
Discover Financial Services,fortune500
Nektar Therapeutics,fortune500
Marriott Vacations Worldwide,fortune500
MGM Resorts International,fortune500
Broadridge Financial Solutions,fortune500
AutoNation,fortune500
J.B. Hunt Transport Services,fortune500
NCR Corporation,fortune500
Robert Half International,fortune500`;
export default csvData;