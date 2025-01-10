import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score

def decisiontree(value1, value2):
    # 第一步：加载数据集
    # 假设数据集是一个 CSV 文件
    df = pd.read_csv('data.csv')

    # 第二步：数据预处理
    # 将 '型号', '机号', '电机型号', '传动方式', '功率', '主轴转速' 列转换为字符串类型
    categorical_columns = ['型号', '机号', '电机型号', '传动方式', '功率', '主轴转速']
    for col in categorical_columns:
        df[col] = df[col].astype(str)

    # 将 '流量' 和 '全压' 列转换为浮点类型
    numerical_columns = ['流量', '全压']
    for col in numerical_columns:
        df[col] = df[col].astype(float)

    # 检查空值并填充为 'null'（如果是空字符串或 NaN）
    for col in categorical_columns:
        df[col] = df[col].fillna('null')  # 填充 NaN
        df[col] = df[col].replace('', 'null')  # 填充空字符串

    # 初始化 LabelEncoders 用于分类变量
    le_model = LabelEncoder()
    le_jihao = LabelEncoder()
    le_dianjihao = LabelEncoder()
    le_chuandong = LabelEncoder()
    le_zhuzhuansuoshu = LabelEncoder()
    le_gonglv = LabelEncoder()

    # 对分类变量进行编码
    df['型号_encoded'] = le_model.fit_transform(df['型号'])
    df['机号_encoded'] = le_jihao.fit_transform(df['机号'])
    df['电机型号_encoded'] = le_dianjihao.fit_transform(df['电机型号'])
    df['传动方式_encoded'] = le_chuandong.fit_transform(df['传动方式'])
    df['主轴转速_encoded'] = le_zhuzhuansuoshu.fit_transform(df['主轴转速'])
    df['功率_encoded'] = le_gonglv.fit_transform(df['功率'])

    # 第三步：准备特征和目标
    X = df[['流量', '全压']]
    y_model = df['型号_encoded']
    y_jihao = df['机号_encoded']
    y_dianjihao = df['电机型号_encoded']

    # 第四步：拆分数据
    X_train, X_test, y_train_model, y_test_model, y_train_jihao, y_test_jihao, y_train_dianjihao, y_test_dianjihao = train_test_split(
        X, y_model, y_jihao, y_dianjihao, test_size=0.2, random_state=42
    )

    # 第五步：训练模型
    # 训练 '型号' 模型
    clf_model = DecisionTreeClassifier()
    clf_model.fit(X_train, y_train_model)

    # 训练 '机号' 模型
    clf_jihao = DecisionTreeClassifier()
    clf_jihao.fit(X_train, y_train_jihao)

    # 训练 '电机型号' 模型
    clf_dianjihao = DecisionTreeClassifier()
    clf_dianjihao.fit(X_train, y_train_dianjihao)

    # 第六步：评估模型
    # 预测 '型号'
    y_pred_model = clf_model.predict(X_test)
    accuracy_model = accuracy_score(y_test_model, y_pred_model)

    # 预测 '机号'
    y_pred_jihao = clf_jihao.predict(X_test)
    accuracy_jihao = accuracy_score(y_test_jihao, y_pred_jihao)

    # 预测 '电机型号'
    y_pred_dianjihao = clf_dianjihao.predict(X_test)
    accuracy_dianjihao = accuracy_score(y_test_dianjihao, y_pred_dianjihao)

    # 第七步：对新数据进行预测
    new_data = pd.DataFrame({
        '流量': [value1],  # 替换为实际值
        '全压': [value2]    # 替换为实际值
    })

    # 预测 '型号', '机号', '电机型号'
    predicted_model = clf_model.predict(new_data)
    predicted_jihao = clf_jihao.predict(new_data)
    predicted_dianjihao = clf_dianjihao.predict(new_data)

    # 解码预测结果
    predicted_model_name = le_model.inverse_transform(predicted_model)
    predicted_jihao_name = le_jihao.inverse_transform(predicted_jihao)
    predicted_dianjihao_name = le_dianjihao.inverse_transform(predicted_dianjihao)

    # 第八步：检索附加信息
    # 根据预测结果过滤原始数据集
    filtered_df = df[
        (df['型号'] == predicted_model_name[0]) &
        (df['机号'] == predicted_jihao_name[0]) &
        (df['电机型号'] == predicted_dianjihao_name[0])
    ]

    # 检查是否有匹配的记录
    if filtered_df.empty:
        chuandong_fangshi = "null"
        zhuzhuansuoshu = "null"
        gonglv = "null"
    else:
        # 处理空值
        chuandong_fangshi = filtered_df['传动方式'].values[0] if not pd.isna(filtered_df['传动方式'].values[0]) else "null"
        zhuzhuansuoshu = filtered_df['主轴转速'].values[0] if not pd.isna(filtered_df['主轴转速'].values[0]) else "null"
        gonglv = filtered_df['功率'].values[0] if not pd.isna(filtered_df['功率'].values[0]) else "null"

    # 将结果组织成字典
    result = {
        "预测的型号": predicted_model_name[0],
        "预测的机号": predicted_jihao_name[0],
        "预测的电机型号": predicted_dianjihao_name[0],
        "传动方式": chuandong_fangshi,
        "主轴转速": zhuzhuansuoshu,
        "功率": gonglv
    }

    # 返回结果
    return result